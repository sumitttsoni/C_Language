#include <stdio.h>

/* Task 3: constant made with #define (no equals sign, no semicolon) */
#define GST_PERCENT 5

int main(void)
{
    /* Banner from Session 2 */
    printf("=====================================\n");
    printf("        SHREE GANESH KIRANA STORE\n");
    printf("        Navrangpura, Ahmedabad\n");
    printf("        Ph: 9XXXXXXXXX\n");
    printf("-------------------------------------\n");
    printf("            TAX INVOICE\n");
    printf("-------------------------------------\n");

    /* Task 4: customer block (lowercase names with underscores) */
    int customer_id = 101;
    float loyalty_points = 45.5f;
    char member_class = 'A';
    double discount_rate = 0.05;

    printf("Customer ID    : %d\n", customer_id);
    printf("Loyalty points : %.1f\n", loyalty_points);
    printf("Member class   : %c\n", member_class);
    printf("Discount rate  : %f\n", discount_rate);
    printf("-------------------------------------\n");

    /* Task 1: three items, one line per item, no arrays or loops */
    char item1_code = 'R';
    int item1_qty = 2;
    float item1_rate = 55.50f;

    char item2_code = 'D';
    int item2_qty = 1;
    float item2_rate = 62.00f;

    char item3_code = 'S';
    int item3_qty = 5;
    float item3_rate = 44.25f;

    printf("Item\tQty\tRate\n");
    printf("%c\t%d\tRs. %.2f\n", item1_code, item1_qty, item1_rate);
    printf("%c\t%d\tRs. %.2f\n", item2_code, item2_qty, item2_rate);
    printf("%c\t%d\tRs. %.2f\n", item3_code, item3_qty, item3_rate);
    printf("-------------------------------------\n");

    /* Task 2: same number in a float and in a double */
    float shop_target_float = 1234567.89f;
    double shop_target_double = 1234567.89;

    printf("Shop target (float)  : %.2f\n", shop_target_float);
    printf("Shop target (double) : %.2f\n", shop_target_double);
    printf("-------------------------------------\n");

    /* Task 3: const variable and bill settings line */
    const float DELIVERY_CHARGE = 20.50f;

    printf("Bill settings: GST %d%%, delivery Rs. %.2f, type %c, %s\n",
           GST_PERCENT, DELIVERY_CHARGE, 'R', "Thank you");

    printf("Thank you, visit again\n");

    return 0;
}