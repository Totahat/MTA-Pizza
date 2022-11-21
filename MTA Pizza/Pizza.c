#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct Pizza{
int length; //pizza length (cm)
int width;  //pizza width (cm)
char doughType; //dough type ('r'/'v'/'w'/'f')
int olives;  //olives amount (0/1/2/3)
int mushrooms; //mushrooms amount (0/1/2/3)
float price;  //pizza price (Without tax)
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
	int ID;
	int delivery;
	float price=0;
	float pizzap, olivep, shroomp, doughp;
	int pricetax;
	int Pizzaamount;
	int i;
	int payment, change;
	int tens, fives, twos, ones;
	printf("Welcome to MTA-Pizza!\n\n*****\n ***\n  *\n\n");
	printf("Please enter your ID number:\n");
	scanf("%d", &ID);
	printf("\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: %.2f NIS for %dx%d size pizza\n", pizzaprice, pizzasize, pizzasize);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS\n", oliveprice);
	printf("Mushrooms: %d NIS\n\n", shroomprice );
	printf("Dough type  for basic size pizza:\n");
	printf("Regular: %d NIS\n", regularDP );
	printf("Vegan: %d NIS\n", veganDP );
	printf("Whole wheat: %d NIS\n", wholewheatDP);
	printf("Gluten free: %d NIS\n", glutenfreeDP);
	printf("How many pizzas would you like to order?");
	scanf("%d", &Pizzaamount);
	printf("\n*************************************************\n");
    for(i=1;i<=Pizzaamount;i++){
	printf("Pizza #%d:",i);
	printf("Please enter your pizza's length (cm):");
	scanf("%d", &pizza.length);
	if ( pizza.length%2==1||pizza.length>pizzasize||pizza.length<minsize){
		pizza.length=pizzasize;
		printf("Invalid length! Basic length was chosen as a default.\n");
	}
	printf("\nPlease enter your pizza's width (cm):");
	scanf("%d", &pizza.width);
	if ( pizza.width%2==1||pizza.width>maxwidth||pizza.width<minsize){
		pizza.length=40;
		printf("Invalid width! Basic width was chosen as a default.\n");
	}
	printf("Please enter the pizza's dough type:");
	printf("r - for regular\n");
    printf("v - for vegan\n");
	printf("w - for whole wheat\n");
    printf("f - for gluten-free\n");
	scanf("%c", pizza.doughType);
	if (pizza.doughType!='r'&&pizza.doughType!='v'&&pizza.doughType!='w'&&pizza.doughType!='f'){
		pizza.doughType='r';
		printf("Invalid choice! Regular dough was chosen as default.\n");
	}
	printf("\nPlease choose the toppings:\n\n");
	printf("Olives (choose 0-3):\n");
	printf("0. None\n");
	printf("1. Whole pizza\n");
	printf("2. Half pizza");
	printf("3. Quarter pizza");
	scanf(" %f", &pizza.olives);
	if (pizza.olives>3||pizza.olives<0){
        pizza.olives=0;
		printf("Invalid choice! Current topping not added.");
	}
	printf("OMushrooms (choose 0-3):\n");
	printf("0. None\n");
	printf("1. Whole pizza\n");
	printf("2. Half pizza");
	printf("3. Quarter pizza");
	scanf(" %f", &pizza.mushrooms);
	if (pizza.mushrooms>3||pizza.mushrooms<0){
        pizza.mushrooms=0;
		printf("Invalid choice! Current topping not added.");
	}
	if (pizza.olives=1&&pizza.mushrooms>=1){
        printf("You have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.");
		pizza.mushrooms=0;
	}
	if ((pizza.olives=2||pizza.olives=3)&&pizza.mushrooms==1){
        printf("You have exceeded the maximum amount  of toppings allowed  on one pizza! Current topping not added.");
		pizza.mushrooms=0;
	}
	pizzap = (float)(pizza.length * pizza.width) / (pizzasize * pizzasize) * pizzaprice;
	switch(pizza.doughType){
		case 'r':
		pizzap = (float)(pizza.length * pizza.width) / (pizzasize * pizzasize) * pizzaprice;
		break;
		case 'v':
		pizzap = (float)(pizza.length * pizza.width) / (pizzasize * pizzasize)* veganDP ;
		break;
		case 'w':
		pizzap = (float)(pizza.length * pizza.width) / (pizzasize * pizzasize)* wholewheatDP;
		break;
		case 'f':
		pizzap = (float)(pizza.length * pizza.width) / (pizzasize * pizzasize) * glutenfreeDP;
		break;
	}
	switch(pizza.olives){
		case 0:
		olivep = 0;
		break;
		case 1:
		olivep = (float)(pizza.length * pizza.width ) / (pizzasize * pizzasize) * oliveprice;
		break;
		case 2:
		olivep = (float)(pizza.length * pizza.width * halfpizza) / (pizzasize * pizzasize) * oliveprice;
		break;
		case 3:
		olivep = (float)(pizza.length * pizza.width * quarterpizza) / (pizzasize * pizzasize) * oliveprice;
		break;
	}
	switch(pizza.mushrooms){
		case 0:
		shroomp = 0;
		break;
		case 1:
		shroomp = (float)(pizza.length * pizza.width ) / (pizzasize * pizzasize) * shroomprice;
		break;
		case 2:
		shroomp = (float)(pizza.length * pizza.width * halfpizza) / (pizzasize * pizzasize) * shroomprice;
		break;
		case 3:
		shroomp = (float)(pizza.length * pizza.width * quarterpizza) / (pizzasize * pizzasize) * shroomprice;
		break;
	}
	pizza.price= pizzap+ shroomp+olivep+doughp;
    printf("Pizza #%d details:\n");
	printf("*******************\n");
	printf("Pizza size: %dx%d", pizza.length, pizza.width);
	printf("Pizza price (without tax): %.2lf", pizza.price);
	price=price+pizza.price;
	}
	printf("\nDo you want delivery for the price of %d NIS? Enter 1 for delivery or 0 for pick-up: ", deliveryprice);
	scanf("%d", &delivery);
	if (delivery!=1||delivery!=0){
		printf("Invalid choice! Pick-up was chosen as a default.");
	}
	price=price+(delivery*deliveryprice);
	pricetax = (int)(price * 1.17);
	printf("\nYour order details:\n");
	printf("*******************\n");
	printf("ID number: %09d\n", ID);
	printf("Number of Pizzas: %d\n", Pizzaamount);
	printf("Total price: %.2f\n", price);
	printf("Total price with tax (rounded down): %d\n", pricetax);
	printf("Please enter your payment:");
	scanf("%d", payment);
	change=payment-pricetax;
	while (change <0){
		printf("Your remaining balance: %d", change*-1);
		printf("Please enter your payment:");
	scanf("%d", payment);
	change=payment-pricetax;
    }
	printf("Your change is %d NIS using:\n");
	if (change>=10){
	while(change/10>0){
		tens+=1;
		change-=10;
	}
	printf("%d coins(s) of ten\n", tens);
	}
	if (change>=5){
	while(change/5>0){
		fives+=1;
		change-=5;
	}
	printf("%d coins(s) of five\n", fives);
	}
	if (change>=2){
	while(change/2>0){
		twos+=1;
		change-=2;
	}
	printf("%d coins(s) of two\n", twos);
	}
	if (change>=1){
	while(change/1>0){
		twos+=1;
		change-=1;
	}
	printf("%d coins(s) of one\n", ones);
	}
	printf("Thank you for your order!");
}