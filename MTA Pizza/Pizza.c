#define _CRT_SECURE_NO_WARNINGS  //313528168 yakir twil
#include <stdio.h>
#include <stdbool.h>
typedef struct Pizza{
int length; //pizza length (cm)
int width;  //pizza width (cm)
char doughType; //dough type ('r'/'v'/'w'/'f')
int olives;  //olives amount (0/1/2/3)
int mushrooms; //mushrooms amount (0/1/2/3)
int tomatos;
int pineapple;
int quarters;
char q1;
char q2;
char q3;
char q4;
double price;  //pizza price (Without tax)
}Pizza;
typedef struct Balance {
	int change;
	int counter;
}Balance;
void printMenu();
int getIDNumber();
int getNumOfPizzas();
int getDelivery();
Pizza getPizzaDimensions();
Pizza getDoughType(Pizza pizza);
Pizza getToppings(Pizza pizza);
int toppingChoice(Pizza pizza);
Pizza getolives(Pizza pizza);
Pizza getToppings(Pizza pizza);
Pizza putToppings(Pizza pizza, char topping, int check);
void printLine(char a, int length);
void printPizzaDetails(Pizza pizza, int i);
void printPizza(Pizza pizza);
void getPayment(int totalPrice);
double calculateDough(char dough, int length, int width);
double calculateToppings(int length, int width, int part, double price);
Balance coinCounter(int change, int decrement);
#define VEGAN_DOUGH_PRICE 5.0 //price for vegan dough constant
#define REGULAR_DOUGH_PRICE 0 //price for regular dough constant
#define WHOLE_WHEAT_DOUGH_PRICE 3.0 //price for whole wheet dough constant
#define GLUTEN_FREE_DOUGH_PRICE 4.0 //price for gluten free dough constant
#define PIZZA_LENGTH 40 //base pizza size constant
#define PIZZA_WIDTH 50 //base pizza size constant
#define PIZZA_PRICE 70.00 // pizza price constant
#define DELIVERY_PRICE 15.0 // delivery price constant
#define OLIVES_PRICE 10.0 // olive price constant
#define MUSHROOMS_PRICE 12.0 // mushrooms price constant
#define HALF_PIZZA 0.5 //multiplier for half pizza toppings
#define QUARTER_PIZZA 0.25 // multiplier for quarter pizza toppings
#define MAX_WIDTH 80 // maximum width value
#define MIN_SIZE 10 // minimum size value
#define Tax 1.17 // tax multiplier
#define TOMATOS_PRICE 9.0
#define PINEAPPLE_PRICE 14.0
#define one 1
#define NO_QUARTERS 0
#define ONE_QUARTER 1
#define TWO_QUARTERS 2
#define THREE_QUARTERS 3
#define FOUR_QUARTERS 4
#define FALSE 0
#define TRUE 1
#define MAX_ID_DIGIT 9
#define NO_TOPPING ' '
#define OLIVES_TOPPINGS 'O'
#define MUSHROOMS_TOPPINGS 'M'
#define TOMATOS_TOPPINGS 'T'
#define PINEAPPLE_TOPPINGS 'P'
#define DECREMENT_TEN 10
#define DECREMENT_FIVE 5
#define DECREMENT_TWO 2
#define DECREMENT_ONE 1

 
void main() {
	Pizza pizza;
	int ID; //variable for ID number
	int delivery; //variable for delivery check
	double totalPrice=0; //variable for total price before taxes
	double pizzaPrice, olivePrice, mushroomPrice,tomatosPrice,pineapplePrice, doughPrice; // variables for each componant price
	int priceTax; //variable for prices after taxes
	int pizzaAmount; // variable to check the amount of pizzas
	int i; // variable to run the for loop
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
	ID=getIDNumber();
	printMenu();
	pizzaAmount = getNumOfPizzas();
		for (i = 1; i <= pizzaAmount; i++) { //starting the loop of building a pizza
			printf("\n*************************************************\n");
			printf("Pizza #%d:\n\n", i);
			pizza = getPizzaDimensions();
			pizza = getDoughType(pizza);
			pizza = getToppings(pizza);
			pizzaPrice = (double)(pizza.length * pizza.width) / (double)(PIZZA_LENGTH * PIZZA_WIDTH) * PIZZA_PRICE;
			doughPrice = calculateDough(pizza.doughType, pizza.length, pizza.width);
			olivePrice = calculateToppings(pizza.length,pizza.width,pizza.olives,OLIVES_PRICE);
			mushroomPrice = calculateToppings(pizza.length, pizza.width, pizza.mushrooms, MUSHROOMS_PRICE);
			tomatosPrice = calculateToppings(pizza.length, pizza.width, pizza.tomatos, TOMATOS_PRICE);
			pineapplePrice = calculateToppings(pizza.length, pizza.width, pizza.pineapple, PINEAPPLE_PRICE);
			pizza.price = (double)(pizzaPrice + mushroomPrice + olivePrice + doughPrice+ tomatosPrice+ pineapplePrice); // calculating the price of the corrent pizza
			printPizzaDetails(pizza, i);
			totalPrice = totalPrice + pizza.price; // adding to the total price of the order
		}
		delivery = getDelivery();
		totalPrice = totalPrice + (delivery * DELIVERY_PRICE); // add the delivery to the total price
		priceTax = (int)(totalPrice * 1.17); //multiply the cprice with the tax rate
		printf("\nYour order details:\n");
		printf("*******************\n");
		printf("ID number: %09d\n", ID);
		printf("Number of pizzas: %d\n", pizzaAmount);
		if (delivery == 1) 
			printf("Delivery\n");
		else
			printf("Pick-up\n");
		printf("Total price: %.2lf\n", totalPrice);
		printf("Total price with tax (rounded down): %d\n", priceTax);
		getPayment(priceTax);
		printf("Thank you for your order!");
	}
int getIDNumber() {
	int id, sum, last, temp1, temp2, corrent, multi, count;
	bool check = TRUE;
	printf("Please enter your ID number:");
	scanf("%d", &id);
	while (check) {
		check = FALSE;
		count = 0;
		sum = 0;
		temp1 = id;
		temp2 = id;
		multi = 2;
		last = temp1 % 10;
		temp1 = temp1 / 10;
		while (temp2 > 0) {
			count += 1;
			temp2 /= 10;
		}
		if (count > MAX_ID_DIGIT||count==FALSE) {
			printf("\nInvalid ID number! Try again.\n");
			printf("Please enter your ID number:");
			check = TRUE;
			scanf("%d", &id);
		}
		else {
			while (temp1 > 0) {
				corrent = (temp1 % 10) * multi;
				if (multi == 2)
					multi = 1;
				else
					multi = 2;
				temp1 = temp1 / 10;
				if (corrent <= 9)
					sum += corrent;
				else
					sum += (1 + corrent % 10);
			}
			sum += last;
			if (sum % 10 != 0) {
				printf("\nInvalid check digit! Try again.\n");
				printf("Please enter your ID number:");
				check = 1;
				scanf("%d", &id);
			}
		}
	}
	return id;
}
void printMenu(){
	printf("\n\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: %.2f NIS for %dx%d size pizza\n\n", PIZZA_PRICE, PIZZA_LENGTH, PIZZA_WIDTH);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %.0lf NIS\n", OLIVES_PRICE);
	printf("Mushrooms: %.0lf NIS\n", MUSHROOMS_PRICE );
	printf("Tomatoes: %.0lf NIS\n", TOMATOS_PRICE);
	printf("Pineapple: %.0lf NIS\n\n", PINEAPPLE_PRICE);
	printf("Dough type for basic size pizza:\n");
	printf("Regular: %d NIS\n", REGULAR_DOUGH_PRICE );
	printf("Vegan: %.0lf NIS\n", VEGAN_DOUGH_PRICE );
	printf("Whole wheat: %.0lf NIS\n", WHOLE_WHEAT_DOUGH_PRICE);
	printf("Gluten free: %.0lf NIS\n\n", GLUTEN_FREE_DOUGH_PRICE);

}
int getNumOfPizzas(){
	int res;
	printf("How many pizzas would you like to order?");
	scanf("%d", &res);
	while (res < 1) {
		printf("Invalid choice! Try again.\n");
	    printf("How many pizzas would you like to order?");
		scanf("%d", &res);
	}
	return res;
}
Pizza getPizzaDimensions() {
	Pizza res;
	printf("Please enter your pizza's length (cm): ");
	scanf("%d", &res.length); //length input
	while (res.length % 2 != 0 || res.length > PIZZA_LENGTH || res.length < MIN_SIZE) { // length check
		printf("Invalid length! Try again.\n");
		printf("Please enter your pizza's length (cm): ");
		scanf("%d", &res.length); //length input
	}
	printf("Please enter your pizza's width (cm): ");
	scanf("%d", &res.width);  //width input
	while (res.width % 2 == 1 || res.width > MAX_WIDTH || res.width < MIN_SIZE) { // length check
		printf("Invalid width! Try again.");
		printf("\nPlease enter your pizza's width (cm): ");
		scanf("%d", &res.width); //length input
	}
	return res;
}
Pizza getDoughType(Pizza pizza) {
	printf("\nPlease enter the pizza's dough type:\n");
	printf("r - for regular\n");
	printf("v - for vegan\n");
	printf("w - for whole wheat\n");
	printf("f - for gluten-free\n");
	scanf(" %c", &pizza.doughType); // dough type input
	while (pizza.doughType != 'r' && pizza.doughType != 'v' && pizza.doughType != 'w' && pizza.doughType != 'f') {
		printf("Invalid choice! Try again.\n");
		printf("\nPlease enter the pizza's dough type:\n");
		printf("r - for regular\n");
		printf("v - for vegan\n");
		printf("w - for whole wheat\n");
		printf("f - for gluten-free\n");
		scanf(" %c", &pizza.doughType); // dough type input
	}
	return pizza;
}
int toppingChoice(Pizza pizza) {
	bool choice = TRUE, max = TRUE;
	int res;
	while (choice || max) {
		choice = FALSE;
		max = FALSE;
		printf("0. None\n");
		printf("1. Whole pizza\n");
		printf("2. Half pizza\n");
		printf("3. Quarter pizza\n");
		scanf(" %d", &res); //tomatoes input
		if (res > 3 && res < 0) {
			choice = TRUE;
			printf("Invalid choice! Try again.\n\n");
		}
		if ((pizza.quarters != 0) && res == 1) {
			printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
			max = TRUE;
		}
		else if (res == 2 && pizza.quarters > TWO_QUARTERS) {
			printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
			max = TRUE;
		}
	}
		return res;
	}
Pizza putToppings(Pizza pizza, char topping,int check) {
	switch (check) {
	case 1:
		pizza.q1 = topping;
		pizza.q2 = topping;
		pizza.q3 = topping;
		pizza.q4 = topping;
		pizza.quarters = FOUR_QUARTERS;
		break;
	case 2:
		if (pizza.quarters == TWO_QUARTERS ) {
			pizza.q3 = topping;
			pizza.q4 = topping;
			pizza.quarters += TWO_QUARTERS;
			return pizza;
		}
		else if (pizza.quarters == ONE_QUARTER) {
			pizza.q2 = topping;
			pizza.q3 = topping;
			pizza.quarters += TWO_QUARTERS;
		}
		else {
			pizza.q1 = topping;
			pizza.q2 = topping;
			pizza.quarters += TWO_QUARTERS;
		}
		break;
	case 3:
		if (pizza.quarters == ONE_QUARTER) {
			pizza.q2 = topping;
			pizza.quarters += ONE_QUARTER;
		}
		else if (pizza.quarters == TWO_QUARTERS) {
			pizza.q3 = topping;
			pizza.quarters += ONE_QUARTER;
		}
		else if (pizza.quarters == THREE_QUARTERS) {
			pizza.q4 = topping;
			pizza.quarters += ONE_QUARTER;
		}
		else {
			pizza.q1 = topping;
			pizza.quarters += ONE_QUARTER;
		}
	}
	return pizza;
}
Pizza getToppings(Pizza pizza) {
	pizza.quarters = NO_QUARTERS;
	pizza.q1 = NO_TOPPING;
	pizza.q2 = NO_TOPPING;
	pizza.q3 = NO_TOPPING;
	pizza.q4 = NO_TOPPING;
	pizza.tomatos = 0;
	pizza.pineapple = 0;
	pizza.mushrooms = 0;
	pizza.olives = 0;
	printf("\nPlease choose the toppings:\n\n");
	printf("Olives (choose 0-3):\n");
	pizza.olives = toppingChoice(pizza);
	pizza = putToppings(pizza, OLIVES_TOPPINGS, pizza.olives);
	if (pizza.quarters == FOUR_QUARTERS)
		return pizza;
	printf("\nMushrooms (choose 0-3):\n");
	pizza.mushrooms = toppingChoice(pizza);
	pizza = putToppings(pizza, MUSHROOMS_TOPPINGS, pizza.mushrooms);
	if (pizza.quarters == FOUR_QUARTERS)
		return pizza;
	printf("\nTomatos (choose 0-3):\n");
	pizza.tomatos = toppingChoice(pizza);
	pizza = putToppings(pizza, TOMATOS_TOPPINGS, pizza.tomatos);
	if (pizza.quarters == FOUR_QUARTERS)
		return pizza;
	printf("\nPineapple (choose 0-3):\n");
	pizza.pineapple = toppingChoice(pizza);
	pizza = putToppings(pizza, PINEAPPLE_TOPPINGS, pizza.pineapple);
	return pizza;
}
void printPizza(Pizza pizza){
	printLine(pizza.doughType, pizza.width);
	int i, j;
	for (i = 2; i < pizza.length; i++) {
		printf("%c", pizza.doughType);
		for (j = 2; j < pizza.width; j++)
			if (i <= pizza.length / 2)
				if (j > pizza.width / 2)
					printf("%c", pizza.q1);
				else 
					printf("%c", pizza.q4);
			else
				if (j > pizza.width / 2)
					printf("%c", pizza.q2);
				else
					printf("%c", pizza.q3);
				
		printf("%c\n", pizza.doughType);
	}
	printLine(pizza.doughType, pizza.width);
}
void printLine(char a,int width) {
	int i;
	for (i = 1; i <= width; i++)
		printf("%c", a);
	printf("\n");
}
double calculateToppings(int length, int width, int part, double price) {
	double res = 0;
	switch (part) { // switch to check the section of the pizza with olives
	case 0:
		res = 0;
		break;
	case 1:
		res = (double)(length * width) / (double)(PIZZA_LENGTH * PIZZA_WIDTH) * (double)price;
		break;
	case 2:
		res = (double)(length * width * HALF_PIZZA) / (double)(PIZZA_LENGTH * PIZZA_WIDTH) * (double)price;
		break;
	case 3:
		res = (double)(length * width * QUARTER_PIZZA) / (double)(PIZZA_LENGTH * PIZZA_WIDTH) * (double)price;
		break;
	}
	return res;
}
double calculateDough(char dough, int length, int width) {
	double res=0;
	switch (dough) { //switch to check the dough type and and calculated the price 
	case 'r':
		res = 0;
		break;
	case 'v':
		res = (double)(length * width) / (PIZZA_LENGTH * PIZZA_WIDTH) * VEGAN_DOUGH_PRICE;
		break;
	case 'w':
		res = (double)(length * width) / (PIZZA_LENGTH * PIZZA_WIDTH) * WHOLE_WHEAT_DOUGH_PRICE;
		break;
	case 'f':
		res = (double)(length * width) / (PIZZA_LENGTH * PIZZA_WIDTH) * GLUTEN_FREE_DOUGH_PRICE;
		break;
	}
	return res;
}
void printPizzaDetails(Pizza pizza, int i) {
	printf("\nPizza #%d details:\n", i);
	printf("*******************\n");
	printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
	printf("Pizza price (without tax): %.2lf\n", pizza.price);
	printPizza(pizza);
}
int getDelivery() {
	int res;
	printf("\n*************************************************");
	printf("\nDo you want delivery for the price of %.0lf NIS? Enter 1 for delivery or 0 for pick-up: ", DELIVERY_PRICE);
	scanf("%d", &res);
	if (res != 1 && res != 0) { //check the delivery value 
		printf("Invalid choice! Try again.");
		printf("\nDo you want delivery for the price of %.0lf NIS? Enter 1 for delivery or 0 for pick-up: ", DELIVERY_PRICE);
		scanf("%d", &res);
	}
	return res;
}
void getPayment(int totalPrice) {
	int payment, balance, change;
	Balance check;
	printf("\nPlease enter your payment: ");
	scanf(" %d", &payment); // takes payment input
	balance = totalPrice - payment; // balance calculation
	while (balance > 0) { // checks if there is a remaining balance
		printf("Your remaining balance is: %d", balance);
		printf("\nPlease enter your payment: ");
		scanf(" %d", &payment);
		balance = balance - payment;
	}
	check.change = balance * -1; // multiply blanace with -1 to get the change needed to return
	if (check.change > 0) {
		printf("Your change is %d NIS using:\n", check.change);
		if (check.change >= 10) {
			check = coinCounter(check.change, DECREMENT_TEN);
			printf("%d coin(s) of ten\n", check.counter);
		}
		if (check.change >= 5) {
			check = coinCounter(check.change, DECREMENT_FIVE);
		    printf("%d coin(s) of five\n", check.counter);
		}
		if (check.change >= 2) {
			check = coinCounter(check.change, DECREMENT_TWO);
			printf("%d coin(s) of two\n", check.counter);
		}
		if (check.change >= 1)
			printf("%d coin(s) of one\n", one);
	}
}
Balance coinCounter(int change,int decrement) {
	Balance res;
	res.change = change;
	res.counter = 0;
	while (res.change / decrement > 0) {
		res.counter += 1;
		res.change -= decrement;
	}
	return res;
}
