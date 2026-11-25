#include <stdio.h>

#define GST_PERCENT 5

int main(void)
{

    printf("=====================================\n");
    printf("        SHREE GANESH KIRANA STORE\n");
    printf("        Navrangpura, Ahmedabad\n");
    printf("        Ph: 9XXXXXXXXX\n");
    printf("-------------------------------------\n");
    printf("            TAX INVOICE\n");
    printf("-------------------------------------\n");

    int customer_id = 101;
    float loyalty_points = 45.5f;
    char member_class = 'A';
    double discount_rate = 0.05;

    printf("Customer ID    : %d\n", customer_id);
    printf("Loyalty points : %.1f\n", loyalty_points);
    printf("Member class   : %c\n", member_class);
    printf("Discount rate  : %f\n", discount_rate);
    printf("-------------------------------------\n");

    char item1_code = 'R';
    int quantity1 = 2;
    float rate1 = 45.50f;

    char item2_code = 'D';
    int quantity2 = 1;
    float rate2 = 120.00f;

    char item3_code = 'S';
    int quantity3 = 3;
    float rate3 = 30.25f;

    float line_total1 = quantity1 * rate1;
    float line_total2 = quantity2 * rate2;
    float line_total3 = quantity3 * rate3;
    float subtotal = line_total1 + line_total2 + line_total3;
    float gst = subtotal * GST_PERCENT / 100.0f;   
    float grand_total = subtotal + gst;

    printf("Item\tQty\tRate\tTotal\n");
    printf("%c\t%d\t%.2f\t%.2f\n", item1_code, quantity1, rate1, line_total1);
    printf("%c\t%d\t%.2f\t%.2f\n", item2_code, quantity2, rate2, line_total2);
    printf("%c\t%d\t%.2f\t%.2f\n", item3_code, quantity3, rate3, line_total3);
    printf("-------------------------------------\n");
    printf("Subtotal    : %.2f\n", subtotal);
    printf("GST (%d%%)   : %.2f\n", GST_PERCENT, gst);
    printf("Grand total : %.2f\n", grand_total);
    printf("-------------------------------------\n");

    float cash = 500.0f;
    int change = (int)cash - (int)grand_total;   
    int notes_100 = change / 100;                
    int rest_after_100 = change % 100;           
    int notes_50 = rest_after_100 / 50;          
    int rest_after_50 = rest_after_100 % 50;     
    int coins_10 = rest_after_50 / 10;          

    printf("Cash paid   : %.2f\n", cash);
    printf("Change      : %d\n", change);
    printf("Rs.100 notes: %d\n", notes_100);
    printf("Rs.50 notes : %d\n", notes_50);
    printf("Rs.10 coins : %d\n", coins_10);
    printf("-------------------------------------\n");

    int free_delivery = subtotal > 250 || cash >= grand_total && quantity1 >= 3;
    int free_delivery_with_brackets = (subtotal > 250 || cash >= grand_total) && quantity1 >= 3;

    printf("Free delivery (no brackets)  : %d\n", free_delivery);
    printf("Free delivery (with brackets): %d\n", free_delivery_with_brackets);
    printf("-------------------------------------\n");

    int bill_no = 100;
    int stock1 = 20;

    printf("Bill no (post-increment): %d\n", bill_no++);  
    printf("Bill no (pre-increment) : %d\n", ++bill_no);   

    stock1 -= quantity1;
    printf("Stock after sale        : %d\n", stock1);      
    stock1--;
    printf("Stock after one more    : %d\n", stock1);     

    printf("-------------------------------------\n");
    printf("Thank you, visit again\n");

    return 0;
}
