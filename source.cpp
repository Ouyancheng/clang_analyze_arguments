// #include <string>
class string {};
class Person {
    public:
        Person(string name, int age);
        void callPerson(string name, int phoneNum, string message, int count); //the static analysis would issue a warning on the terminal for this function, because it has more than 3 parameters
        void sixsixsix(int a, int b, int c, int d, int e, int f) {
            return;
        }
    private:
        string name;
        int age;
};