#include <stdio.h>


/* Given an array of integers, return a new array such that each element at index i of 
 * the new array is the product of all the numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 */

int rightEleProduct(int arr[], int i, int n) {
    int mul = 1;
    for(int r = i+1; r < n; r++) {
        mul = mul * arr[r];
    }
    printf("mul[%d] n[%d] i[%d]\n", mul, n, i);
    return mul;
}
int leftEleProduct(int arr[],int i) {
    int mul = 1;
    for(int l = 0; l < i; l++) {
        mul = mul * arr[l];
    }
    printf("mul[%d] i[%d]\n", mul, i);
    return mul;
}

int dcp2_m2(void){
    int arr[] = /*{1, 2, 3, 4, 5}*/
                {3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int retArr[n];
    int mul;

    for (int i = 0; i < n; i++) {
        retArr[i] = leftEleProduct(arr, i) * rightEleProduct(arr, i, n);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", retArr[i]);
    }
    return 0;
}

int dcp2_m1(void){
    int arr[] = /*{1, 2, 3, 4, 5}*/
                {3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int retArr[n];
    int mul;

    printf("n=%d\n", n);
    for (int i = 0; i < n; i++) {
        mul = 1;
        for (int j = n-1; j >= 0 ; j--) {
            if (i == j)
                continue;

            mul = mul * arr[j];
        }
        retArr[i] = mul;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", retArr[i]);
    }
    return 0;
}

/*
* This problem was recently asked by Google.
* Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
* For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
*/
int dcp1_m2(void){
    //Lets try to solve using hash

    return 0;
}

int dcp1_m1(void){
    int k = 468;
    int isFound = 0;

    //printf("Enter Value of K:");
    //scanf("%d", &k);

    int arr[] = /*{10, 15, 3, 7}
                {0, -1, 2, -3, 1}*/
                {335,501,170,725,479,359,963,465,706,146,282,828,962,492,\
                 996,943,828,437,392,605,903,154,293,383,422,717,719,896,\
                 448,727,772,539,870,913,668,300,36,895,704,812,323,334};
    int n = 42;

    for(int outer = 0; outer < n; outer++) {
        if (isFound)
            break;

        int findNo = k - arr[outer];
        for(int inner = 0; inner < n; inner++) {
            if (inner == outer)
                continue;

            printf("findNo[%d] arr[inner]:%d inner[%d] outer[%d]\n", findNo, arr[inner], inner, outer);
            if (arr[inner] == findNo) {
                printf("Two No(s): %d, %d\n", arr[outer], findNo);
                isFound = 1;
                break;
            }
        }
    } 
    if (!isFound)
        printf("No two no exists whose sum is %d\n", k);

    return 0;
}

int main() {
    /*
    dcp1_m1();
    dcp1_m2();
    dcp2_m1();
    */

    dcp2_m2();

    return 0;
}
