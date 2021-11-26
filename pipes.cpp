
     #include <iostream>  
    using namespace std;  
    int main()  
    {  
      int n, i, m=0, flag=0;  
      cout << "Enter the Number to check Prime: ";  
      cin >> n;  
      m=n/2;  
      for(i = 2; i <= m; i++)  
      {  
          if(n % i == 0)  
          {  
              cout<<"Number is not Prime."<<endl;  
              flag=1;  
              break;  
          }  
      }  
      if (flag==0)  
          cout << "Number is Prime."<<endl;  
      return 0;  
    }  
    
    for(int i = 0; i < 10; i++)
 {
 pid = fork();
 processCounter++;
 
 if (pid)
 {
 if (pid == -1) 
{
 cout << "Error creating child process!\n";
 exit(-1);
 }
 parentProc(secondPipe[0],firstPipe[1]);
 }
 else
 {
 childProc(firstPipe[0], secondPipe[1]);
 } 
 }
 void parentProc(int readPipe, int writePipe) {
 int leftInterval;
 int rightInterval;
 int primeNumbers[200];
 int size;
 
 leftInterval = 1000 * (processCounter - 1);
 rightInterval = 1000 * processCounter;
 
 write(writePipe, &leftInterval, sizeof(int));
 write(writePipe, &rightInterval, sizeof(int));
 read(readPipe, &size, sizeof(int));
 read(readPipe, primeNumbers, sizeof(primeNumbers));
 
 for(int i = 0; i < size; i++)
 {
 cout << primeNumbers[i] << " "; 
 }
 cout << endl;
}

	
  void childProc(int readPipe, int writePipe) {
 int leftInterval;
 int rightInterval;
 int nr;
 int primeNumbers[200];
 int position = 0;
 int size = 0;
 
 read(readPipe, &leftInterval, sizeof(leftInterval));
 read(readPipe, &rightInterval, sizeof(rightInterval));
 
 for(int i = leftInterval; i < rightInterval; i++)
 {
 nr = prim(i);
 if(nr != 0)
 {
 primeNumbers[position++] = nr;
 size++;
 }
 }
 
 write(writePipe, &size, sizeof(int));
 write(writePipe, primeNumbers, sizeof(primeNumbers));
 
 cout << "Process "<< processCounter <<" has ended."<<endl;
 exit(1);
}
