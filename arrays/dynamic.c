#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CAPACITY;
void display(int *);
int size(int *);
bool is_empty(int *);
void at(int *, int);
int *push(int *, int);
int *insert(int *, int, int);
int *prepend(int *, int);
int pop(int *);
int *delete(int *, int);
int *rem(int *, int);

int main(void)
{
    int *a;
    printf("Enter no. of elements to store: ");
    scanf("%d", &CAPACITY);
    a = malloc((CAPACITY + 1) * sizeof(int));
    printf("Storing %d integers...\n", CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
        *(a + i) = i;
    *(a + CAPACITY) = -999;

    if (is_empty(a))
        printf("\nEmpty\n");
    display(a);

    at(a, 1);
    a = push(a, 99);
    display(a);

    a = insert(a, 2, 99);
    display(a);

    a = prepend(a, 99);
    display(a);

    int p = pop(a);
    printf("\nPoped element: %d\n", p);
    display(a);

    a = delete (a, 5);
    display(a);

    a = rem(a, 99);
    display(a);


    return 0;
}

void display(int *a)
{
    int i = 0;
    printf("Size: %d | Capacity: %d\n", size(a), CAPACITY);
    printf("----Integers:----\n");
    while (*(a + i) != -999)
    {
        printf("%d: %d\n", i, *(a + i));
        i++;
    }
}
int size(int *a)
{
    int i = 0;
    while (*(a + i) != -999)
        i++;
    return i;
}
bool is_empty(int *a)
{
    if (size(a) == 0)
        return true;
    return false;
}
void at(int *a, int i)
{
    if (i >= CAPACITY)
        printf("\nIndex out of bound\n");
    else
        printf("\nReturning element at %d: %d\n", i, *(a + i));
}
int *push(int *a, int x)
{
    printf("\n+ + + + Pushing %d + + + +\n", x);
    CAPACITY += 1;
    a = realloc(a, sizeof(int) * CAPACITY + 1);
    *(a + CAPACITY - 1) = x;
    *(a + CAPACITY) = -999;
    return a;
}
int *insert(int *a, int index, int x)
{
    CAPACITY += 1;
    int i = CAPACITY;
    a = realloc(a, sizeof(int) * CAPACITY + 1);
    printf("\n* * * Inserting %d at %d * * *\n", x, index);
    while (i >= index)
    {
        *(a + i) = *(a + i - 1);
        i--;
    }
    *(a + index) = x;
    return a;
}
int *prepend(int *a, int x)
{
    CAPACITY += 1;
    int i = CAPACITY;
    a = realloc(a, sizeof(int) * CAPACITY + 1);
    printf("\n- - - - Prepending %d - - - -\n", x);
    while (i > 0)
    {
        *(a + i) = *(a + i - 1);
        i--;
    }
    *a = x;
    return a;
}
int pop(int *a)
{
    int p = *(a + size(a) - 1);
    CAPACITY--;
    a = realloc(a, sizeof(int) * CAPACITY + 1);
    *(a + CAPACITY) = -999;
    return p;
}
int *delete(int *a, int i)
{
    printf("\n- - - Deleting item at %d - - -\n", i);
    while (i < CAPACITY)
    {
        *(a + i) = *(a + i + 1);
        i++;
    }
    CAPACITY--;
    a = realloc(a, sizeof(int) * CAPACITY + 1);
    *(a + CAPACITY) = -999;
    return a;
}

int *rem(int *a, int x)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (*(a + i) == x)
            a = delete (a, i);
    }
    return a;
}
