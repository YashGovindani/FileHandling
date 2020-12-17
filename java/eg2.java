import java.io.*;
class eg2
{
public static void main(String args[])
{
try
{
File file=new File("friends.data");
if(file.exists()==false)
{
System.out.println("No friends added");
return;
}
RandomAccessFile randomAccessFile;
randomAccessFile=new RandomAccessFile(file,"rw");
if(randomAccessFile.length()==0)
{
randomAccessFile.close();
System.out.println("No friends added");
return;
}
int rollNumber;
String name;
while(randomAccessFile.getFilePointer()<randomAccessFile.length())
{
rollNumber=Integer.parseInt(randomAccessFile.readLine());
name=randomAccessFile.readLine();
System.out.println("Roll Number : "+rollNumber+", Name : "+name);
}
randomAccessFile.close();
}catch(IOException ioException)
{
System.out.println(ioException);
}catch(NumberFormatException numberFormatException)
{
System.out.println(numberFormatException);
}
}
}
