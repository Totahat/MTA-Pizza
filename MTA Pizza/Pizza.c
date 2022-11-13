#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define pizzasize 40
#define pizzaprice 60.00
#define deliveryprice 15
#define oliveprice 10
#define shroomprice 12 
 

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
	printf("Basic pizza: %.2f NIS for %dx%d size pizza\n", pizzaprice, pizzasize, pizzasize);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS\n", oliveprice);
	printf("Mushrooms: %d NIS\n\n", shroomprice);
	printf("Please enter your pizza's length (cm):");
	scanf("%d", &length);
	printf("\nPlease enter your pizza's width (cm):");
	scanf("%d", &width);
	printf("\nPlease choose the toppings:\n\n");
	printf("Olives - Enter 1 for the whole pizza\n");
	printf("0.5 for half\n");
	printf("0.25 for quarter\n");
	printf("or 0 for none:");
	scanf(" %f", &olive);
	printf("\nMushrooms - Enter 1 for the whole pizza\n");
	printf("0.5 for half\n");
	printf("0.25 for quarter\n");
	printf("or 0 for none:");
	scanf(" %f", &shroom);
	printf("\nDo you want delivery for the price of %d NIS? Enter 1 for delivery or 0 for pick-up: ", deliveryprice);
	scanf("%d", &delivery);
	pizzap = (float)(length * width) / (pizzasize * pizzasize) * pizzaprice;
	olivep = (length * width * olive) / (pizzasize * pizzasize) * oliveprice;
	shroomp= (length * width * shroom) / (pizzasize * pizzasize) * shroomprice;
	price = pizzap + olivep + shroomp+delivery* deliveryprice;
	pricetax = (int)(price * 1.17);
	printf("\nYour order details:\n");
	printf("*******************\n");
	printf("ID number: %09d\n", ID);
	printf("Pizza size: %dx%d\n", length, width);
	printf("Total price: %.2f\n", price);
	printf("Total price with tax (rounded down): %d\n", pricetax);
	printf("Thank you for your order!");
}