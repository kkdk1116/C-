#include <stdio.h>

int main()
{
	int n, i ,j, timeSlice;
	int Burst[10], Wait[10], Response[10];
	float A_Wait = 0, A_Response = 0, A1_Response = 0;
	
	printf("10 이하의 프로세스 숫자를 입력하세요 :");
	scanf("%d", &n);
	
	for (i = 0; i<n; i++)
	{
		printf("Process %d:", i);
		scanf("%d", &Burst[i]);
	}
	
	printf("타임 슬라이스를 입력하세요: ");
	scanf("%d", &timeSlice);
	
	Wait[0] = 0;
	
	for (i = 0; i<n; i++)
	{
		Wait[i] = 0;
		for (j = 0; j<i; j++)
		Wait[i] += Burst[j];
	}
	
	
	for (i = 0; i<n; i++)
	{
		Response[i] = Burst[i] + Wait[i];
		A_Wait += Wait[i];
		A_Response += Response[i];
		
		
		printf("\n Process %d (B/W/R) \t\t %d \t\t %d \t\t %d\n", i, Burst[i], Wait[i], Response[i]);
		
	}
			
	A1_Response = A_Response;
	
	A_Wait = A_Wait / i;
	A_Response = A_Response / i;
	printf("평균대기시간 :%f\n", A_Wait); // 평균 대기 시간 
	printf("평균반환시간 :%f\n", A_Response); // 평균 반환 시간
	


	while(1)
	{
		for(j=0; j<n+1; j++)
		{
			if(Burst[j]>0)
			{
				Burst[j] = Burst[j]-timeSlice;
				printf("Process %d\n", j);
				A1_Response = A1_Response-timeSlice;
			}
		}
		if(A1_Response<0)
			break;					
	} 

	return 0;
}
	

