/* INF2610 - TP1
/ Matricule 1 :
/ Matricule 2 :
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

static const char *SMALL_C = "Small";
static const char *MEDIUM_C = "Medium";
static const char *LARGE_C = "Large";

typedef struct Wheel
{
    int id;
    bool isRearWheel;
} Wheel;

typedef struct Wing
{
    int *id;
} Wing;

typedef struct Plane
{
    char *id;
    char planeType[10];
    bool isAvailable;
    struct Wheel *wheels;
    struct Wing *wings;
} Plane;

Wheel *createWheels(int id)
{
    int n = 7;
    Wheel *wheels = (Wheel *)calloc(n, sizeof(Wheel));
    for (int i = 0; i < n; i++)
    {
        Wheel *wheel = (Wheel *)malloc(sizeof(Wheel));
        wheel->id = id + i;
        wheel->isRearWheel = i < 3 ? false : true;
        wheels[i] = *wheel;
    }

    return wheels;
}

void populateWingAttribute(int id, Wing *wing)
{
    int n = 9;
    wing->id = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
    {
        wing->id[i] = id % (n + 1);
        id = id / (n + 1);
    }
}

Wing *createWings(long id)
{
    Wing wing1;
    Wing wing2;
    Wing *wings = (Wing *)malloc(2 * sizeof(Wing));
    populateWingAttribute(id, &wing1);
    populateWingAttribute(id + 1, &wing2);

    wings[0] = wing1;
    wings[1] = wing2;

    return wings;
}

char *transformId(const char *id, int i)
{
    char *resultId = (char *)malloc(strlen(id) * sizeof(char));
    int current_int_id = atoi(id) + i;
    sprintf(resultId, "%d", current_int_id);

    return resultId;
}

void createPlanes(Plane **planes, const char *id, int size)
{
    int count = size;
    int i = 0;
    while (count > 0)
    {
        Plane *plane = (Plane *)malloc(sizeof(Plane));
        plane->id = transformId(id, i);
        plane->isAvailable = true;
        plane->wheels = createWheels(atoi(id));
        plane->wings = createWings(atoi(id));
        planes[i] = plane;
        i++;
        count--;
    }
};

void setAvailability(Plane *plane, bool isAvailable)
{
    plane->isAvailable = isAvailable;
}

char **getAvailablePlanes(Plane **planes, int size)
{
    char **idArray = (char **)malloc(size * sizeof(char *));
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (planes[i]->isAvailable)
        {
            idArray[j++] = planes[i]->id;
        }
    }

    return idArray;
}

int arrayToNumber(const int *id, int length)
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result = result * 10 + id[i];
    }

    return result;
}

void setPlaneType(Plane *plane)
{

    int wingIdentifier = arrayToNumber(plane->wings[0].id, 9);
    printf("%d\n", wingIdentifier);
    int moduloValue = wingIdentifier % 9;

    if (moduloValue <= 2)
    {
        strncpy(plane->planeType, SMALL_C, sizeof(plane->planeType));
    }
    else if (moduloValue > 2 && moduloValue <= 6)
    {
        strncpy(plane->planeType, MEDIUM_C, sizeof(plane->planeType));
    }
    else
    {
        strncpy(plane->planeType, LARGE_C, sizeof(plane->planeType));
    }
}

Plane **getPlanesByType(Plane **planes, int size, const char *type)
{
    int count = 0;
    Plane **planesTab = (Plane **)malloc(size * sizeof(Plane *));
    for (int i = 0; i < size; i++)
    {
        if (strcmp(planes[i]->planeType, type) == 0)
        {
            planesTab[count++] = planes[i];
        }
    }

    return planesTab;
}

int main(int argc, char **argv)
{
    /* Remove comment once the code is completed for the given section to test */
    int id = 789;

    /* PARTIE 2 - [10 points] */

    /* Create wheel - [2 points] */
    Wheel *wheels = createWheels(id);
    printf("%s", wheels[4].isRearWheel ? "true" : "false");
    printf("\nFIN Wheel \n");

    /* Create wing - [4 points] */
    long longId = 5678;
    Wing *wings = createWings(longId);
    for (int j = 0; j < 9; j++)
    {
        printf("%d", wings[0].id[j]);
    }

    printf("\nFIN Wings \n");

    /* Create plane - [4 points] */
    char chaine[10];
    snprintf(chaine, sizeof(chaine), "%d", id);
    int numberOfPlanes = 3;
    Plane **planes = (Plane **)malloc(numberOfPlanes * sizeof(Plane *));
    createPlanes(planes, chaine, 3);

    for (int k = 0; k < numberOfPlanes; k++)
    {
        printf("Plane %d - id : %s \n", k, planes[k]->id);
    }

    /* PARTIE 3 - [6 points] */

    /* Set availabilities - [1 point] */
    setAvailability(planes[0], false);
    Plane plane = *planes[0];
    printf("Set Ava - %s \n", plane.isAvailable ? "true" : "false");

    /* Get available planes - [1 point] */
    char **ids = getAvailablePlanes(planes, numberOfPlanes);
    printf("Get Ava - ");
    for (int k = 0; k < numberOfPlanes; k++)
    {
        if (ids[k] != NULL)
        {
            printf("%s, ", ids[k]);
        }
    }
    printf("\n");

    /* Classify planes - [2 points] */
    setPlaneType(planes[1]);
    plane = *planes[1];
    printf("Type Plane : %s \n", plane.planeType);

    /* Return type specific planes - [2 points] */
    char planeType[] = "Medium";
    Plane **planesTyped = getPlanesByType(planes, numberOfPlanes, planeType);
    printf("Get Planes by Type  %s - ", planeType);
    for (int k = 0; k < numberOfPlanes; k++)
    {
        if (planesTyped[k] != NULL)
        {
            printf("%s, ", planesTyped[k]->id);
        }
    }
    printf("\n");
}
