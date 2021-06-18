class x{
  public:
  void print(double a,int x) {cout<<"Class x"<<endl;}
};

class y: public x{
 public:
 void print(char a) {cout<<"Class y char: "<<a<<endl;}
};

/* The above code is overriding print but this does not achieve runtime polymorphism 
   this merely achive name overriding and hides the parent class function in the derived class

   **********This does not require signatures to be same***************/

class x{
  public:
  virtual void print(double a) {cout<<"Class x"<<endl;}
};

class y: public x{
 public:
 void print(char a) {cout<<"Class y char: "<<a<<endl;}
};

/* This above code, is the actual overriding that is used in other oop languages as well.
   
   *******In this case the signatures have to exact match to enable runtime polymorphism */
