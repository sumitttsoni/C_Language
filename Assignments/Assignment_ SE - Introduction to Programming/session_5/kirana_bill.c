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

    char item_code;
    int quantity;
    char member;
    float rate = 0;          


    printf("Enter item code (A = Rice, B = Dal, C = Oil): ");
    scanf(" %c", &item_code);         
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Member? (Y/N): ");
    scanf(" %c", &member);

    switch (item_code)
    {
        case 'A':
            rate = 60.00f;
            printf("Item: Rice\n");
            break;
        case 'B':
            rate = 120.00f;
            printf("Item: Dal\n");
            break;
        case 'C':
            rate = 150.00f;
            printf("Item: Oil\n");
            break;
        default:
            printf("Invalid item code\n");
            return 0;                  
    }

    float subtotal = rate * quantity;

    float discount_percent;
    if (subtotal <= 200)
        discount_percent = 0;
    else if (subtotal <= 500)
        discount_percent = 5;
    else
        discount_percent = 10;

    float discount_amount = subtotal * discount_percent / 100.0f;
    float after_discount = subtotal - discount_amount;

    float member_discount = 0;
    if (member == 'Y' || member == 'y')
    {
        if (subtotal > 300)
        {
            member_discount = 10;
        }
    }
    float after_member = after_discount - member_discount;

    float gst = after_member * GST_PERCENT / 100.0f;
    float grand_total = after_member + gst;

    printf("-------------------------------------\n");
    printf("Item code       : %c\n", item_code);
    printf("Quantity        : %d\n", quantity);
    printf("Rate            : %.2f\n", rate);
    printf("Subtotal        : %.2f\n", subtotal);
    printf("Discount (%.0f%%) : %.2f\n", discount_percent, discount_amount);
    printf("Member discount : %.2f\n", member_discount);
    printf("GST (%d%%)       : %.2f\n", GST_PERCENT, gst);
    printf("Grand total     : %.2f\n", grand_total);
    printf("-------------------------------------\n");
    printf("Thank you, visit again\n");

    return 0;
}