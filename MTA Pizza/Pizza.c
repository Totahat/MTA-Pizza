#define _CRT_SECURE_NO_WARNINGS  //313528168 yakir twil
#include <stdio.h>
#include <stdbool.h>
typedef struct Pizza{
int length; //pizza length (cm)
int width;  //pizza width (cm)
char doughType; //dough type ('r'/'v'/'w'/'f')
int olives;  //olives amount (0/1/2/3)
int mushrooms; //mushrooms amount (0/1/2/3)
double tomatoes;
double pineapple;
char q1;
char q2;
char q3;
char q4;
double price;  //pizza price (Without tax)
}Pizza;
#define VEGAN_DOUGH_PRICE 5 //price for vegan dough constant
#define REGULAR_DOUGH_PRICE 0 //price for regular dough constant
#define WHOLE_WHEAT_DOUGH_PRICE 3 //price for whole wheet dough constant
#define GLUTEN_FREE_DOUGH_PRICE 4 //price for gluten free dough constant
#define PIZZA_SIZE 40 //base pizza size constant
#define PIZZA_PRICE 60.00 // pizza price constant
#define DELIVERY_PRICE 15 // delivery price constant
#define OLIVES_PRICE 10 // olive price constant
#define MUSHROOMS_PRICE 12 // mushrooms price constant
#define HALF_PIZZA 0.5 //multiplier for half pizza toppings
#define QUARTER_PIZZA 0.25 // multiplier for quarter pizza toppings
#define MAX_WIDTH 80 // maximum width value
#define MIN_SIZE 10 // minimum size value
#define Tax 1.17 // tax multiplier
#define TOMATOES_PRICE 9
#define PINEAPPLE_PRICE 14
 
void main() {
	Pizza pizza;
	int ID; //variable for ID number
	int delivery; //variable for delivery check
	double totalPrice=0; //variable for total price before taxes
	double pizzaPrice, olivePrice, mushroomPrice, doughPrice; // variables for each componant price
	int priceTax; //variable for prices after taxes
	int pizzaAmount; // variable to check the amount of pizzas
	int balance; // variable for the remaining payment required
	int i; // variable to run the for loop
	int payment=0, change; // variables for the change and payment 
	int tens=0, fives=0, twos=0, ones=0; // variables for the change count
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
	ID=getIDNumber();
	printMenu();
	printf("How many pizzas would you like to order?");
	scanf("%d", &pizzaAmount);  
	if (pizzaAmount <= 0) { //checking if the client dont want pizzas
		printf("Thank you and goodbye");
	}
	else {
		for (i = 1; i <= pizzaAmount; i++) { //starting the loop of building a pizza
			printf("\n\n*************************************************\n");
			printf("Pizza #%d:\n\n", i);
			printf("Please enter your pizza's length (cm):");
			scanf("%d", &pizza.length); //length input
			if (pizza.length % 2 == 1 || pizza.length > PIZZA_SIZE || pizza.length < MIN_SIZE) { // length check
				pizza.length = PIZZA_SIZE;
				printf("\nInvalid length! Basic length was chosen as a default.");
			}
			printf("\nPlease enter your pizza's width (cm):");
			scanf("%d", &pizza.width);  //width input
			if (pizza.width % 2 == 1 || pizza.width > MAX_WIDTH || pizza.width < MIN_SIZE) { //width check
				pizza.width = PIZZA_SIZE;
				printf("\nInvalid width! Basic width was chosen as a default.");
			}
			printf("\n\nPlease enter the pizza's dough type:\n");
			printf("r - for regular\n");
			printf("v - for vegan\n");
			printf("w - for whole wheat\n");
			printf("f - for gluten-free\n");
			scanf(" %c", &pizza.doughType); // dough type input
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
			scanf(" %d", &pizza.olives); // olives input
			if (pizza.olives > 3 || pizza.olives < 0) { // olives check
				pizza.olives = 0;
				printf("Invalid choice! Current topping not added.");
			}
			printf("\nMushrooms (choose 0-3):\n");
			printf("0. None\n");
			printf("1. Whole pizza\n");
			printf("2. Half pizza\n");
			printf("3. Quarter pizza\n");
			scanf(" %d", &pizza.mushrooms); //mushrooms input
			if (pizza.mushrooms > 3 || pizza.mushrooms < 0) { // mushroom check
				pizza.mushrooms = 0;
				printf("\nInvalid choice! Current topping not added.\n");
			}
			if (pizza.olives == 1 && pizza.mushrooms >= 1) { //olives and mushroom not more than entire size check
				printf("\nYou have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.\n");
				pizza.mushrooms = 0;
			}
			if ((pizza.olives == 2 || pizza.olives == 3) && pizza.mushrooms == 1) { //olives and mushroom not more than entire size check
				printf("\nYou have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.\n");
				pizza.mushrooms = 0;
			}
			pizzaPrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * PIZZA_PRICE;
			switch (pizza.doughType) { //switch to check the dough type and and calculated the price 
			case 'r':
				doughPrice = 0;
				break;
			case 'v':
				doughPrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * VEGAN_DOUGH_PRICE;
				break;
			case 'w':
				doughPrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * WHOLE_WHEAT_DOUGH_PRICE;
				break;
			case 'f':
				doughPrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * GLUTEN_FREE_DOUGH_PRICE;
				break;
				default

			}
			switch (pizza.olives) { // switch to check the section of the pizza with olives
			case 0:
				olivePrice = 0;
				break;
			case 1:
				olivePrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * OLIVES_PRICE;
				break;
			case 2:
				olivePrice = (double)(pizza.length * pizza.width * HALF_PIZZA) / (PIZZA_SIZE * PIZZA_SIZE) * OLIVES_PRICE;
				break;
			case 3:
				olivePrice = (double)(pizza.length * pizza.width * QUARTER_PIZZA) / (PIZZA_SIZE * PIZZA_SIZE) * OLIVES_PRICE;
				break;
			}
			switch (pizza.mushrooms) { //switch to check the section of the pizza with olives
			case 0:
				mushroomPrice = 0;
				break;
			case 1:
				mushroomPrice = (double)(pizza.length * pizza.width) / (PIZZA_SIZE * PIZZA_SIZE) * MUSHROOMS_PRICE;
				break;
			case 2:
				mushroomPrice = (double)(pizza.length * pizza.width * HALF_PIZZA) / (PIZZA_SIZE * PIZZA_SIZE) * MUSHROOMS_PRICE;
				break;
			case 3:
				mushroomPrice = (double)(pizza.length * pizza.width * QUARTER_PIZZA) / (PIZZA_SIZE * PIZZA_SIZE) * MUSHROOMS_PRICE;
				break;
			}
			pizza.price = pizzaPrice + mushroomPrice + olivePrice + doughPrice; // calculating the price of the corrent pizza
			printf("\nPizza #%d details:\n", i);
			printf("*******************\n");
			printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
			printf("Pizza price (without tax): %.2lf", pizza.price);
			totalPrice = totalPrice + pizza.price; // adding to the total price of the order
		}
		printf("\n\n*************************************************");
		printf("\nDo you want delivery for the price of %d NIS? Enter 1 for delivery or 0 for pick-up: ", DELIVERY_PRICE);
		scanf("%d", &delivery);
		if (delivery != 1 && delivery != 0) { //check the thelivery value 
			printf("\nInvalid choice! Pick-up was chosen as a default.");
			delivery = 0;
		}
		totalPrice = totalPrice + (delivery * DELIVERY_PRICE); // add the delivery to the total price
		priceTax = (int)(totalPrice * 1.17); //multiply the cprice with the tax rate
		printf("\n\nYour order details:\n");
		printf("*******************\n");
		printf("ID number: %09d\n", ID);
		printf("Number of pizzas: %d\n", pizzaAmount);
		printf("Total price: %.2lf\n", totalPrice);
		printf("Total price with tax (rounded down): %d\n", priceTax);
		printf("\nPlease enter your payment:");
		scanf(" %d", &payment); // takes payment input
		balance = priceTax - payment; // balance calculation
		while (balance>0) { // checks if there is a remaining balance
			printf("\nYour remaining balance is: %d", balance);
			printf("\nPlease enter your payment:");
			scanf(" %d", &payment);
			balance=balance-payment;
		}
		change = balance * -1; // multiply blanace with -1 to get the change needed to return
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
int getIDNumber(){
	int id, sum,last, temp, corrent,multi=2;
	bool check=2;
	printf("Please enter ID number:");
	scanf("%d", &id);
	while(check==false){
	temp=id;
	last=id%10;
	while(temp>0){
		corrent=(temp%10)*multi;
		if(multi==2)
		multi=1;
		else 
		multi=2;
		temp=temp/10;
		while(corrent!=0){
			sum+=corrent/10;
			corrent=corrent%10;
		}
	}
	if(last%2==0)
	sum+=id;
	else
	sum+=id-1;
	if(sum%10==0)
	check=1;
	else{
		printf("invalid ID number, please enter a new number");
        scanf("%d", &id);
	}
	}
	return id;
}
void printMenu(){
	printf("\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: %.2f NIS for %dx%d size pizza\n\n", PIZZA_PRICE, PIZZA_SIZE, PIZZA_SIZE);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS\n", OLIVES_PRICE);
	printf("Mushrooms: %d NIS\n", MUSHROOMS_PRICE );
	printf("Tomatoes: %d NIS\n", TOMATOES_PRICE);
	printf("Pineapple: %d NIS\n\n", PINEAPPLE_PRICE);
	printf("Dough type for basic size pizza:\n");
	printf("Regular: %d NIS\n", REGULAR_DOUGH_PRICE );
	printf("Vegan: %d NIS\n", VEGAN_DOUGH_PRICE );
	printf("Whole wheat: %d NIS\n", WHOLE_WHEAT_DOUGH_PRICE);
	printf("Gluten free: %d NIS\n\n", GLUTEN_FREE_DOUGH_PRICE);

}
int getNumOfPizzas(){
	
}