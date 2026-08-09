#include <stdio.h>
#define MAX 100
struct Sparse
{
    int row;
    int col;
    int value;
};
// Function to input matrix
void inputMatrix(int a[MAX][MAX], int m, int n)
{
    int i, j;

    printf("Enter the elements of matrix:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
// Function to display matrix
void displayMatrix(int a[MAX][MAX], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
// Function to check sparse matrix
int isSparse(int a[MAX][MAX], int m, int n)
{
    int i, j;
    int zero = 0, nonzero = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                zero++;
            else
                nonzero++;
        }
    }
    printf("\nNumber of zero elements = %d", zero);
    printf("\nNumber of non-zero elements = %d\n", nonzero);
    if (zero > nonzero)
        return 1;
    else
        return 0;
}
// Function to find transpose using 2D array
void transpose2D(int a[MAX][MAX], int t[MAX][MAX], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            t[j][i] = a[i][j];
        }
    }
}
// Function to convert matrix into sparse structure
int createSparse(int a[MAX][MAX], struct Sparse s[], int m, int n)
{
    int i, j, k = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                s[k].row = i;
                s[k].col = j;
                s[k].value = a[i][j];
                k++;
            }
        }
    }

    return k;
}
// Function to find transpose using structure
void transposeStructure(struct Sparse s[], struct Sparse t[], int count, int m, int n)
{
    int i, j, k = 0;

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < count; i++)
        {
            if (s[i].col == j)
            {
                t[k].row = s[i].col;
                t[k].col = s[i].row;
                t[k].value = s[i].value;
                k++;
            }
        }
    }
}
// Function to display sparse structure
void displaySparse(struct Sparse s[], int count)
{
    int i;

    printf("Row\tColumn\tValue\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%d\t%d\n",
               s[i].row,
               s[i].col,
               s[i].value);
    }
}
int main()
{
    printf("NAME : ASMIT PAL\nROLL NO : 25052035   Section : CS48\n");
    int a[MAX][MAX];
    int t[MAX][MAX];
    struct Sparse s[MAX];
    struct Sparse st[MAX];
    int m, n;
    int count;
    // Input size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    // Input matrix
    inputMatrix(a, m, n);
    printf("\nOriginal Matrix:\n");
    displayMatrix(a, m, n);
    // Check sparse
    if (isSparse(a, m, n))
    {
        printf("\nThe matrix is a SPARSE MATRIX.\n");

        // (i) Transpose using 2D array
        transpose2D(a, t, m, n);

        printf("\nTranspose using 2D Array:\n");
        displayMatrix(t, n, m);

        // Convert to structure
        count = createSparse(a, s, m, n);

        printf("\nSparse Matrix using Structure:\n");
        displaySparse(s, count);

        // (ii) Transpose using structure
        transposeStructure(s, st, count, m, n);

        printf("\nTranspose using Structure:\n");
        displaySparse(st, count);
    }
    else
    {
        printf("\nThe matrix is NOT a sparse matrix.\n");
    }
    return 0;
}