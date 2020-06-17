#include <iostream>

using namespace std;

class Dodawanie {
    public:
        int a;
        int b;
        Dodawanie() {}
        Dodawanie(int c, int d) : a(c), b(d) {}
        Dodawanie operator+ (Dodawanie &obj) {
            Dodawanie suma;
            suma.a = a + obj.a;
            suma.b = b + obj.b;
            return suma;
        }
};

int main()
{
    Dodawanie A(3, 6);
    Dodawanie B(7, 8);
    Dodawanie C;
    C = A + B;

    cout<<"a-"<<C.a<<" b-"<<C.b<<endl;
    return 0;
}
