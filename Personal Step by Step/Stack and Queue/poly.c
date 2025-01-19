#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

Term *createTerm(int coefficient, int exponent)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(Term **poly, int coefficient, int exponent)
{
    Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL || (*poly)->exponent < exponent)
    {
        newTerm->next = *poly;
        *poly = newTerm;
        return;
    }
    Term *current = *poly;
    while (current->next != NULL && current->next->exponent >= exponent)
    {
        current = current->next;
    }
    if (current->exponent == exponent)
    {
        current->coefficient += coefficient;
    }
    else
    {
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

void displayPolynomial(Term *poly)
{
    if (!poly)
    {
        printf("0\n");
        return;
    }
    while (poly)
    {
        if (poly->coefficient > 0 && poly != NULL)
        {
            printf("+ ");
        }
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    printf("\n");
}

Term *addPolynomials(Term *poly1, Term *poly2)
{
    Term *result = NULL;
    while (poly1 && poly2)
    {
        if (poly1->exponent > poly2->exponent)
        {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0)
            {
                addTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1)
    {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2)
    {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

void inputPolynomial(Term **poly)
{
    int terms, coef, exp;
    printf("Enter number of terms: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++)
    {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        addTerm(poly, coef, exp);
    }
}

int main()
{
    Term *poly1 = NULL;
    Term *poly2 = NULL;
    int choice;

    while (1)
    {
        printf("\nPolynomial Operations:\n");
        printf("1. Input first polynomial\n");
        printf("2. Input second polynomial\n");
        printf("3. Display first polynomial\n");
        printf("4. Display second polynomial\n");
        printf("5. Add polynomials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            poly1 = NULL;
            inputPolynomial(&poly1);
            break;
        case 2:
            poly2 = NULL;
            inputPolynomial(&poly2);
            break;
        case 3:
            printf("First Polynomial: ");
            displayPolynomial(poly1);
            break;
        case 4:
            printf("Second Polynomial: ");
            displayPolynomial(poly2);
            break;
        case 5:
            printf("Sum of Polynomials: ");
            Term *sum = addPolynomials(poly1, poly2);
            displayPolynomial(sum);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
