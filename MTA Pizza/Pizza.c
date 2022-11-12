#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int ID;
	int length, width, delivery;
	float shroom, olive, price;
	float pizzap, olivep, shroomp;
	int pricetax;
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
	printf("Please enter your ID number:\n");
	scanf("%d", &ID);
	printf("\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: 60.00 NIS for 40x40 size pizza\n");
	printf("Toppings for basic  size pizza:\n");
	printf("Olives: 10 NIS\n");
	printf("Mushrooms: 12 NIS\n\n");
	printf("Please enter your pizza's length (cm):");
	scanf("%d", &length);
	printf("\nPlease enter your pizza's width (cm):");
	scanf("%d", &width);
	printf("\nPlease choose the toppings:\n\n");
	printf("Olives - Enter 1 for the whole pizza\n");
	printf("0.5 for half\n");
	printf("0.25 for quarter\n");
	printf("or 0 for none:");
	scanf("%f", &olive);
	printf("\nMushrooms - Enter 1 for the whole pizza\n");
	printf("0.5 for half\n");
	printf("0.25 for quarter\n");
	printf("or 0 for none:");
	scanf("%f", &shroom);
	printf("\nDo you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick-up: ");
	scanf("%d", &delivery);
	pizzap = (float)(length * width) / 1600 * 60;
	olivep = (length * width*olive) / 1600 * 10;
	shroomp= (length * width * shroom) / 1600 * 12;
	price = pizzap + olivep + shroomp+delivery*15;
	pricetax = (int)(price * 1.17);
	printf("\nYour order details:\n");
	printf("*******************\n");
	printf("ID number: %09d\n", ID);
	printf("Pizza size: %dX%d\n", length, width);
	printf("Total price: %.2f\n", price);
	printf("Total price with tax (rounded down): %d\n", pricetax);
	printf("Thank you for your order!");
}