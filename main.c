#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define NUM_TEACHERS 5

struct TeacherRating
{
    int age;
    int id;
    int rating;
    int married;
    char name[MAX_NAME_LEN];
};

const char teacher_choices[NUM_TEACHERS][MAX_NAME_LEN] =
{
    "JonAlf Dyrland-Weaver",
    "Peter Brooks",
    "David Hanna",
    "Josina Dunkel",
    "Stan Kats"
};

int get_rand(int lower, int upper);
struct TeacherRating* create_TeacherRating(const char* name);
void print_TeacherRating(struct TeacherRating* t);
void set_rating(struct TeacherRating* t, int rating);

struct TeacherRating* create_TeacherRating(const char* name)
{
    struct TeacherRating* t = malloc(sizeof(struct TeacherRating));
    t->age = get_rand(0, 200);
    t->id = rand();
    t->rating = get_rand(0, 6); // out of five
    t->married = get_rand(0, 6);
    strncpy(t->name, name, MAX_NAME_LEN);
    return t;
}

// https://www.geeksforgeeks.org/generating-random-number-range-c/
int get_rand(int lower, int upper)
{
    return (rand() % (upper - lower)) + lower;
}

void print_TeacherRating(struct TeacherRating* t)
{
    printf("Teacher %d: %s, rating: %d, age: %d status: %s\n",
                    t->id, t->name, t->rating, t->age, t->married ? "married" : "not married");
}

void set_rating(struct TeacherRating* t, int rating)
{
    t->rating = rating;
}

int main(void)
{
    srand(time(0));
    int i;
    struct TeacherRating* ratings[NUM_TEACHERS];
    for (i = 0; i < NUM_TEACHERS; i++)
    {
        ratings[i] = create_TeacherRating(teacher_choices[i]);
    }
    for (i = 0; i < NUM_TEACHERS; i++)
    {
        print_TeacherRating(ratings[i]);
    }
    printf("Teacher ratings are all set to 0\n");
    for (i = 0; i < NUM_TEACHERS; i++)
    {
        set_rating(ratings[i], 0);
    }
    for (i = 0; i < NUM_TEACHERS; i++)
    {
        print_TeacherRating(ratings[i]);
    }

    // IMPORTANT: FREE ratings
    for (i = 0; i < NUM_TEACHERS; i++)
    {
        free(ratings[i]);
    }
    return 0;
}
