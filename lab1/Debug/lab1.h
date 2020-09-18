namespace PROG_1 {

    struct Int {
        int key;
        int col; 
        int n;
        bool unique;
    };

    int getNum(int&);
    Int** create(Int**, int, int*);
    void errase(Int**, int);
    void output(Int**, int, int);
    void output(int*, int);
    int* createMas(Int**, int);
}