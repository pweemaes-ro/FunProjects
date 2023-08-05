#include <stdio.h>

/* Each transform string starts with the direction of the roll for  which it
* is applicable (direction = transform[i][0] for all valid 0 <= i < 4). */
char* transforms[4] = { "LDRUL", "RDLUR", "FDBUF", "BDFUB" };

char* get_transform(const char direction) {
	/* Return transform string for direction (NULL if direction invalid). */
	for (int i = 0; i < sizeof(transforms) / sizeof(transforms[0]); i++)
		if (transforms[i][0] == direction)
			return transforms[i];
	return NULL;
}

char get_next_face(const char* transform, const char current_face) {
	/* Return next face for value on current face with given transformation. */
	for (int i = 0; i < 4; i++)
		if (transform[i] == current_face)
			return transform[i + 1];
	return current_face;
}

void roll(char dice[6][3], const char direction) {
	/* Perform roll in directon for dice.*/
	char* transform = get_transform(direction);
	for (int i = 0; i < 6; i++)
		dice[i][1] = get_next_face(transform, dice[i][1]);
}

void main() {
	/* A dice has 6 sides, each side has info about the value ("A" through "F") 
	and the location of the face ("U", "D", "F", "B", "L" or "R" for up, down, 
	front, back, left or right face. */
	char dice[6][3] = { "CF", "BR", "AB", "FD", "EL", "DU" };
	
	/* Each roll is a direction in which the dice is rolled. Valid values are "L" 
	(left), "R" (right), "F" (front) and "B" (back). */
	char* rolls = "LLFFRR";

	while (*rolls)
		roll(dice, *rolls++);

	for (int i = 0; i < 6; i++)
		printf("Value on %c face = %c\n", dice[i][1], dice[i][0]);
}
