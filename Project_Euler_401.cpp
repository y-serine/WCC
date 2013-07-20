#include<stdio.h>
//#include<Windows.h>
#include<math.h>

#define NUMMAX 1000000000000000
#define MOD 1000000000

//全体的にオーバーフロー注意


//nまでの2乗の和
long long sum2(long long n){
  long long n2,n3;
	n=n%MOD;
	n2=n*(n+1);
	n3=(2*n+1);
	//dividing by 2
	if(n2&1){
		n3=n3>>1;
	}else{
		n2=n2>>1;
	}
	//dividing by 3
	if(n2%3){
		n3=n3/3;
	}else{
		n2=n2/3;
	}
	n2=n2%MOD;
	//n3=n3%MOD;
	n2=(n2*n3)%MOD;
	return n2;
}	

long long SIGMA2(long long MAX){
	//MAXの平方根をとる。これ以上の約数は発見済み
	long long ROOT=(long long)sqrt((long double)MAX);
	//if(!(((ROOT*ROOT)<=MAX)&&((ROOT+1)*(ROOT+1)>MAX))){printf("Error.");return 0;}

	long long sum=0;
	long long cnt;
	for(long long i=1;i<=ROOT;i++){
		cnt=(long long)(MAX/i);//MAXまでにiの倍数がいくつあるか
		sum+=sum2(cnt)-sum2(i);//iより大きく(i*x)がMAX以下整数となるxの2乗和
		sum+=(((cnt-i+1)%MOD)*(i*i%MOD));//それ(xたち)とペアになるiで2乗和
		//if(sum<0){sum+=MOD;}
		sum=sum%MOD;
	}
	return sum;
}




int main(void){
	long long num=NUMMAX;
	long long SIG2=SIGMA2(num);
	FILE* fp;
	fp=fopen("output.txt","w");
	printf("SIGMA2(%lld)=%lld\n",num,SIG2);
	fprintf(fp,"SIGMA2(%lld)=%lld\n",num,SIG2);
	//Sleep(3200);
	return 0;
}
