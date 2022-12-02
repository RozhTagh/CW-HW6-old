#include <stdio.h>
#include <math.h>

int power(int a, int b){

    int result = 1;

    for(int i =0; i<b; i++)
        result = result * a;

    return result;
}



int base1_to_base10(int num, int base){

    int i = 0;
    int x;
    int sum = 0;

    while (num!=0){
        x = num%10;
        sum = sum + (x*power(base,i));
        num = num/10;
        i++;
    }

    return sum;

}

int base2_to_base10(int num, int base){

    int i = 0;
    int x;
    int sum = 0;

    while (num!=0){
        x = num%10;
        sum = sum + (x*power(base,i));
        num = num/10;
        i++;
    }

    return sum;

}

int base10_to_base2(int num, int base){

    int i = 0;
    int sum = 0;
    int x;

    while(num!=0){

        x = num%base;
        num = num/base;
        sum = sum + (x* power(10,i));
        i++;
    }

    return sum;

}

int digitnum (int num){

    int i = 0;
    while(num!=0){
        num = num/10;
        i++;
    }

    return i;
}


int main(){

    int base1, base2, num;
    scanf("%d%d%d", &base1, &base2, &num);

    int result1 = base1_to_base10(num, base1);
    //printf("%d\n", result1);

    int result2 = base10_to_base2(result1, base2);
    //printf("%d\n", result2);

    int digitcount = digitnum(result2);
    //printf("%d\n",digitcount);

    if (digitcount%2==0){
        int right = result2 % power(10,digitcount/2);
        int left = result2 / power(10,digitcount/2);
        int final_result = base2_to_base10(right, base2) + base2_to_base10(left, base2);
        printf("%d\n", base10_to_base2(final_result, base2));
    }

    else{
        result2 = result2 * 10;
        int right = result2 % power(10,(digitcount+1)/2);
        int left = result2 / power(10,(digitcount+1)/2);
        int final_result = base2_to_base10(right, base2) + base2_to_base10(left, base2);
        printf("%d\n", base10_to_base2(final_result, base2));
    }


    return 0;
}
