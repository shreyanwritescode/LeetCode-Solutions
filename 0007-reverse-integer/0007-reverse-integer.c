int reverse(int x){
    int t=x;
    double s=0;
    while(t!=0){
        int d=t%10;
        s=s*10+d;
        t=t/10;
    }
    if(s>=(int)(pow(2,31)-1)||s<=(int)(pow(-2,31))) return 0;
    return s;
}