class RCC_c{
    public:
    int add(int x, int y){
        return x+y;
    }
};

RCC_c RCC;

int main(){
    volatile int *x = (int *) 7;
    *x = RCC.add(5, 6);
    return 0;
}