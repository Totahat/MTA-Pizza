#define _CRT_SECURE_NO_WARNINGS  //313528168 yakir twil
#include <stdio.h>
#include <stdbool.h>
typedef struct Pizza{
int length; //pizza length (cm)
int width;  //pizza width (cm)
char doughType; //dough type ('r'/'v'/'w'/'f')
double olives;  //olives amount (0/0.25/0.5/1)
double mushrooms; //mushrooms amount (0/0.25/0.5/1)
double tomatos; //tomatos amount (0/0.25/0.5/1)
double pineapple; // pineapple ammount (0/0.25/0.5/1)
int quarters; //total amount of quarters with toppings (1/2/3/4)
char q1; //topping type of the first quarter (O/M/T/P)
char q2; //topping type of the second quarter (O/M/T/P)
char q3; //topping type of the third quarter (O/M/T/P)
char q4; //topping type of the forth quarter (O/M/T/P)
double price;  //pizza price (Without tax)
}Pizza;

typedef struct Balance { //struct for the change and coin counter
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
double toppingChoice(Pizza pizza);
Pizza getolives(Pizza pizza);
Pizza getToppings(Pizza pizza);
Pizza putToppings(Pizza pizza, char topping, double check);
void printLine(char a, int length);
void printPizzaDetails(Pizza pizza, int i);
void printPizza(Pizza pizza);
void getPayment(int totalPrice);
double calculateDough(char dough, int length, int width);
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
#define TOMATOS_PRICE 9.0 //price of tomatos toppings
#define PINEAPPLE_PRICE 14.0 // price of pineapple toppings
#define one 1 //to put the value of one
#define NO_QUARTERS 0 //no quarters with toppings
#define ONE_QUARTER 1 // 1 quarter with tippoings
#define TWO_QUARTERS 2 // 2 quarters with toppings
#define THREE_QUARTERS 3 // 3 quarters with toppings
#define FOUR_QUARTERS 4 //4 quarters with toppings
#define FALSE 0 // false for bool
#define TRUE 1 // true for bool
#define MAX_ID_DIGIT 9 // mamimum number of digis for ID number
#define NO_TOPPING ' ' // no toppings on quarter
#define OLIVES_TOPPINGS 'O' // olive topping on quarter
#define MUSHROOMS_TOPPINGS 'M' //mushroom topping on quarter
#define TOMATOS_TOPPINGS 'T' //tomatos topping on quarter
#define PINEAPPLE_TOPPINGS 'P' // pineapple topping on quarter
#define DECREMENT_TEN 10 // decrement of 10 for change
#define DECREMENT_FIVE 5 // decrement of 5 for change
#define DECREMENT_TWO 2 // decrement of 2 for change
#define DECREMENT_ONE 1 // decrement of 1 for change 
#define REGULAR_CHAR 'r' //char for regular dough
#define GLUTEN_FREE_CHAR 'f' //char for gluten free dough
#define WHOLE_WHEAT_CHAR 'w'//char for whole-wheat dough
#define VEGAN_CHAR 'v' //char for vegan dough

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
	ID=getIDNumber();                                       // call for function to get id number from client
	printMenu();                                            // call for function to print menu
	pizzaAmount = getNumOfPizzas();                         //call fo function to get ammount of pizzas
		for (i = 1; i <= pizzaAmount; i++) {                //starting the loop of building a pizza
			printf("\n*************************************************\n");
			printf("Pizza #%d:\n\n", i);
			pizza = getPizzaDimensions();
			pizza = getDoughType(pizza);
			pizza = getToppings(pizza);
			pizzaPrice = (double)(pizza.length * pizza.width) / (double)(PIZZA_LENGTH * PIZZA_WIDTH) * PIZZA_PRICE;
			doughPrice = calculateDough(pizza.doughType, pizza.length, pizza.width);
			olivePrice = (double)(pizza.length * pizza.width * pizza.olives) / (PIZZA_LENGTH * PIZZA_WIDTH) * OLIVES_PRICE;
			mushroomPrice = (double)(pizza.length * pizza.width * pizza.mushrooms) / (PIZZA_LENGTH * PIZZA_WIDTH) * MUSHROOMS_PRICE;
			tomatosPrice = (double)(pizza.length * pizza.width * pizza.tomatos) / (PIZZA_LENGTH * PIZZA_WIDTH) * TOMATOS_PRICE;
			pineapplePrice = (double)(pizza.length * pizza.width * pizza.pineapple) / (PIZZA_LENGTH * PIZZA_WIDTH) * PINEAPPLE_PRICE;
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
	//function to get id and check if it is according to the algorithm and if the length is ok
int getIDNumber() { //function to get id and check if it is according to the algorithm and if the length is ok
	int id, sum, last, temp1, temp2, corrent, multi, count;
	bool check = TRUE;
	printf("Please enter your ID number:");
	scanf("%d", &id);
	while (check) {
		check = FALSE;                    //the function get an input and copy it to 2 testers.
		count = 0;                        //temp1 checks if the id is ok with the id algoritem
		sum = 0;                          //temp2 checks if the number of integers in the input is between 1-9
		temp1 = id;
		temp2 = id;
		multi = 2;
		last = temp1 % 10;
		temp1 = temp1 / 10;
		while (temp2 > 0) {
			count += 1;
			temp2 /= 10;
		}
		if (count > MAX_ID_DIGIT||id==0) {
			printf("\nInvalid ID number! Try again.\n");
			printf("Please enter your ID number:");
			check = TRUE;
			scanf("%d", &id);
		}
		else {
			while (temp1 > 0) {                       //this loop checks the algorithm of the id on the number
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
				check = TRUE;
				scanf("%d", &id);
			}
		}
	}
	return id;
}
void printMenu(){                            //function to print the menu
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
int getNumOfPizzas(){         //function to get the number of pizzas
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
Pizza getPizzaDimensions() {             //function to get the dimensions of the pizza
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
Pizza getDoughType(Pizza pizza) { //function to get dough type and checks if it is one of the options
	bool check=TRUE;
	while (check) {
		check=FALSE;
		printf("\nPlease enter the pizza's dough type:\n");
	    printf("%c - for regular\n", REGULAR_CHAR);
	    printf("%c - for vegan\n", VEGAN_CHAR);
	    printf("%c - for whole wheat\n", WHOLE_WHEAT_CHAR);
	    printf("%c - for gluten-free\n", GLUTEN_FREE_CHAR);
		scanf(" %c", &pizza.doughType); // dough type input
		switch(pizza.doughType){
			case VEGAN_CHAR:
			case GLUTEN_FREE_CHAR:
			case REGULAR_CHAR:
			case WHOLE_WHEAT_CHAR:
			break;
			default:
				printf("Invalid choice! Try again.\n");
				check=TRUE;
		}
	}
	return pizza;
}
/*
the function get input for corrent topping choice
checks if the input will fill more than 4 quarters
if it does make the client choose again
*/
double toppingChoice(Pizza pizza) { //function to get inpot for corrent topping choice 
	bool check = TRUE;              // checks if it will fill more than a 4 quarters
	double res;
	int input, quarterwsWithToppings;
	while (check) {
		quarterwsWithToppings = pizza.quarters;
		check = FALSE;
		res = 0;
		printf("0. None\n");
		printf("1. Whole pizza\n");
		printf("2. Half pizza\n");
		printf("3. Quarter pizza\n");
		scanf(" %d", &input);
		switch (input) {
		case 0: 
			break;
		case 1: 
			quarterwsWithToppings += 4;
			res = 1;
			break;
		case 2:
			quarterwsWithToppings += 2;
			res = 0.5;
			break;
		case 3:
			quarterwsWithToppings += 1;
			res = 0.25;
			break;
		default:
			check = TRUE;
			printf("Invalid choice! Try again.\n\n");
		}
		if (quarterwsWithToppings>4) {
			printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
			check = TRUE;
		}
	}
		return res;
	}
Pizza putToppings(Pizza pizza, char topping,double toppings) { 
	int check = (int)(toppings * 4);
	switch (check) {
	case 4:                          //this function gets a type of topping and the value of the input
		pizza.q1 = topping;          // it fills the quarters variable and the char variables for the pizza print
		pizza.q2 = topping;
		pizza.q3 = topping;
		pizza.q4 = topping;
		pizza.quarters = FOUR_QUARTERS;
		break;
	case 2:
		if (pizza.quarters == TWO_QUARTERS ) {
			pizza.q3 = topping;
			pizza.q4 = topping;
		}
		else if (pizza.quarters == ONE_QUARTER) {
			pizza.q2 = topping;
			pizza.q3 = topping;
		}
		else {
			pizza.q1 = topping;
			pizza.q2 = topping;
		}
		pizza.quarters += TWO_QUARTERS;
		break;
	case 1:
		if (pizza.quarters == ONE_QUARTER) {
			pizza.q2 = topping;
		}
		else if (pizza.quarters == TWO_QUARTERS) {
			pizza.q3 = topping;
		}
		else if (pizza.quarters == THREE_QUARTERS) {
			pizza.q4 = topping;
		}
		else {
			pizza.q1 = topping;
		}
		pizza.quarters += ONE_QUARTER;
	}
	return pizza;
}
/*
This function gets as input pizza details 
IT\t gets toppings from user and 
It returns updated pizza struct
*/
Pizza getToppings(Pizza pizza) {      // this function gets the input for all toppings 
	pizza.quarters = NO_QUARTERS;     //it will exit if the quarters ammount gets to 4
	pizza.q1 = NO_TOPPING;            //starts with reseting all the chars for the pizza print
	pizza.q2 = NO_TOPPING;            // and reset all the toppings to zero incase of early return to main
	pizza.q3 = NO_TOPPING;            // for each topping it calld for toppingChoice to get input and putToppings
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
void printPizza(Pizza pizza){                     // this function prints the pizza with the toppings choice according to size chosen
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
void printLine(char a,int width) { // this funcion prints a line of same char for the dough
	int i;
	for (i = 1; i <= width; i++)
		printf("%c", a);
	printf("\n");
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
void printPizzaDetails(Pizza pizza, int i) {   //a function to print the pizza details
	printf("\nPizza #%d details:\n", i);
	printf("*******************\n");
	printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
	printf("Pizza price (without tax): %.2lf\n", pizza.price);
	printPizza(pizza);
}
int getDelivery() {  // this function get the inpit if the client want delivery or pick up
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
void getPayment(int totalPrice) {   // this function get the payment from client and prints the change
	int payment, balance;
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
Balance coinCounter(int change,int decrement) { //tihs function counts the number of coins for each coin
	Balance res;
	res.change = change;
	res.counter = 0;
	while (res.change / decrement > 0) {
		res.counter += 1;
		res.change -= decrement;
	}
	return res;
}
