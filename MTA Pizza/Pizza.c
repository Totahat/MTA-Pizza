#define _CRT_SECURE_NO_WARNINGS  //313528168 yakir twil
#include <stdio.h>
typedef struct Pizza{
int length; //pizza length (cm)
int width;  //pizza width (cm)
char doughType; //dough type ('r'/'v'/'w'/'f')
int olives;  //olives amount (0/1/2/3)
int mushrooms; //mushrooms amount (0/1/2/3)
double price;  //pizza price (Without tax)
}Pizza;
#define veganDP 5 //price for vegan dough constant
#define regularDP 0 //price for regular dough constant
#define wholewheatDP 3 //price for whole wheet dough constant
#define glutenfreeDP 4 //price for gluten free dough constant
#define pizzasize 40 //base pizza size constant
#define pizzaprice 60.00 // pizza price constant
#define deliveryprice 15 // delivery price constant
#define oliveprice 10 // olive price constant
#define shroomprice 12 // mushrooms price constant
#define halfpizza 0.5 //multiplier for half pizza toppings
#define quarterpizza 0.25 // multiplier for quarter pizza toppings
#define maxwidth 80 // maximum width value
#define minsize 10 // minimum size value
 
void main() {
	Pizza pizza;
	int ID;  //
	int delivery;
	double price=0;
	double pizzap, olivep, shroomp, doughp;
	int pricetax;
	int Pizzaamount;
	int balance;
	int i; // counter for the for loop
	int payment=0, change;
	int tens=0, fives=0, twos=0, ones=0;
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
	printf("Please enter your ID number:\n");
	scanf("%d", &ID);
	printf("\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: %.2f NIS for %dx%d size pizza\n\n", pizzaprice, pizzasize, pizzasize);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS\n", oliveprice);
	printf("Mushrooms: %d NIS\n\n", shroomprice );
	printf("Dough type for basic size pizza:\n");
	printf("Regular: %d NIS\n", regularDP );
	printf("Vegan: %d NIS\n", veganDP );
	printf("Whole wheat: %d NIS\n", wholewheatDP);
	printf("Gluten free: %d NIS\n\n", glutenfreeDP);
	printf("How many pizzas would you like to order?");
	scanf("%d", &Pizzaamount);
	if (Pizzaamount <= 0) {
		printf("Thank you and goodbye");
	}
	else {
		for (i = 1; i <= Pizzaamount; i++) {
			printf("\n\n*************************************************\n");
			printf("Pizza #%d:\n\n", i);
			printf("Please enter your pizza's length (cm):");
			scanf("%d", &pizza.length);
			if (pizza.length % 2 == 1 || pizza.length > pizzasize || pizza.length < minsize) {
				pizza.length = pizzasize;
				printf("\nInvalid length! Basic length was chosen as a default.");
			}
			printf("\nPlease enter your pizza's width (cm):");
			scanf("%d", &pizza.width);
			if (pizza.width % 2 == 1 || pizza.width > maxwidth || pizza.width < minsize) {
				pizza.width = pizzasize;
				printf("\nInvalid width! Basic width was chosen as a default.");
			}
			printf("\n\nPlease enter the pizza's dough type:\n");
			printf("r - for regular\n");
			printf("v - for vegan\n");
			printf("w - for whole wheat\n");
			printf("f - for gluten-free\n");
			scanf(" %c", &pizza.doughType);
			if (pizza.doughType != 'r' && pizza.doughType != 'v' && pizza.doughType != 'w' && pizza.doughType != 'f') {
				pizza.doughType = 'r';
				printf("Invalid choice! Regular dough was chosen as a default.\n");
			}
			printf("\nPlease choose the toppings:\n\n");
			printf("Olives (choose 0-3):\n");
			printf("0. None\n");
			printf("1. Whole pizza\n");
			printf("2. Half pizza\n");
			printf("3. Quarter pizza\n");
			scanf(" %d", &pizza.olives);
			if (pizza.olives > 3 || pizza.olives < 0) {
				pizza.olives = 0;
				printf("Invalid choice! Current topping not added.");
			}
			printf("\nMushrooms (choose 0-3):\n");
			printf("0. None\n");
			printf("1. Whole pizza\n");
			printf("2. Half pizza\n");
			printf("3. Quarter pizza\n");
			scanf(" %d", &pizza.mushrooms);
			if (pizza.mushrooms > 3 || pizza.mushrooms < 0) {
				pizza.mushrooms = 0;
				printf("\nInvalid choice! Current topping not added.\n");
			}
			if (pizza.olives == 1 && pizza.mushrooms >= 1) {
				printf("\nYou have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.\n");
				pizza.mushrooms = 0;
			}
			if ((pizza.olives == 2 || pizza.olives == 3) && pizza.mushrooms == 1) {
				printf("\nYou have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.\n");
				pizza.mushrooms = 0;
			}
			pizzap = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * pizzaprice;
			switch (pizza.doughType) {
			case 'r':
				doughp = 0;
				break;
			case 'v':
				doughp = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * veganDP;
				break;
			case 'w':
				doughp = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * wholewheatDP;
				break;
			case 'f':
				doughp = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * glutenfreeDP;
				break;
				default

			}
			switch (pizza.olives) {
			case 0:
				olivep = 0;
				break;
			case 1:
				olivep = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * oliveprice;
				break;
			case 2:
				olivep = (double)(pizza.length * pizza.width * halfpizza) / (pizzasize * pizzasize) * oliveprice;
				break;
			case 3:
				olivep = (double)(pizza.length * pizza.width * quarterpizza) / (pizzasize * pizzasize) * oliveprice;
				break;
			}
			switch (pizza.mushrooms) {
			case 0:
				shroomp = 0;
				break;
			case 1:
				shroomp = (double)(pizza.length * pizza.width) / (pizzasize * pizzasize) * shroomprice;
				break;
			case 2:
				shroomp = (double)(pizza.length * pizza.width * halfpizza) / (pizzasize * pizzasize) * shroomprice;
				break;
			case 3:
				shroomp = (double)(pizza.length * pizza.width * quarterpizza) / (pizzasize * pizzasize) * shroomprice;
				break;
			}
			pizza.price = pizzap + shroomp + olivep + doughp;
			printf("\nPizza #%d details:\n", i);
			printf("*******************\n");
			printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
			printf("Pizza price (without tax): %.2lf", pizza.price);
			price = price + pizza.price;
		}
		printf("\n\n*************************************************");
		printf("\nDo you want delivery for the price of %d NIS? Enter 1 for delivery or 0 for pick-up: ", deliveryprice);
		scanf("%d", &delivery);
		if (delivery != 1 && delivery != 0) {
			printf("\nInvalid choice! Pick-up was chosen as a default.");
			delivery = 0;
		}
		price = price + (delivery * deliveryprice);
		pricetax = (int)(price * 1.17);
		printf("\n\nYour order details:\n");
		printf("*******************\n");
		printf("ID number: %09d\n", ID);
		printf("Number of pizzas: %d\n", Pizzaamount);
		printf("Total price: %.2lf\n", price);
		printf("Total price with tax (rounded down): %d\n", pricetax);
		printf("\nPlease enter your payment:");
		scanf(" %d", &payment);
		balance = pricetax - payment;
		while (balance>0) {
			printf("\nYour remaining balance is: %d", balance);
			printf("\nPlease enter your payment:");
			scanf(" %d", &payment);
			balance=balance-payment;
		}
		change = balance * -1;
		if (change > 0) {
			printf("\nYour change is %d NIS using:\n", change);
			if (change >= 10) {
				while (change / 10 > 0) {
					tens += 1;
					change -= 10;
				}
				printf("%d coin(s) of ten\n", tens);
			}
			if (change >= 5) {
				while (change / 5 > 0) {
					fives += 1;
					change -= 5;
				}
				printf("%d coin(s) of five\n", fives);
			}
			if (change >= 2) {
				while (change / 2 > 0) {
					twos += 1;
					change -= 2;
				}
				printf("%d coin(s) of two\n", twos);
			}
			if (change >= 1) {
				while (change / 1 > 0) {
					ones += 1;
					change -= 1;
				}
				printf("%d coin(s) of one\n", ones);
			}
		}
		printf("Thank you for your order!");
	}
}