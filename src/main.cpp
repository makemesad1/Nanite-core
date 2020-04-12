class {
    public:
    int add(int x, int y){
        return x+y;
    }
}RCC;


int main(){
    volatile int *x = (int *) 7;
    *x = RCC.add(*x, 6);
    return 0;
} 

