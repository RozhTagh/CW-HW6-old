#include <stdio.h>
#include <math.h>

int base1_to_base10(int num, int base){

    int i = 0;
    int x;
    int sum = 0;

    while (num!=0){
        x = num%10;
        sum = sum + (x*pow(base,i));
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
        sum = sum + (x* pow(10,i));
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

    int result = base10_to_base2(result1, base2);

    int digitcount = digitnum(result);

    if (digitcount%2==0){
        int right = result/pow(10,digitcount/2);
        int left = result % (int)pow(10,digitcount/2);
        printf("%d", right + left);
    }

    else{
        result = result * 10;
        int right = result/pow(10,(digitcount+1)/2);
        int left = result % (int)pow(10,(digitcount+1)/2);
        printf("%d", right + left);
    }


    return 0;
}
