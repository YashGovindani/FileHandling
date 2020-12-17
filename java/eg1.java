import java.io.*;
class eg1
{
public static void main(String args[])
{
try
{
BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(System.in));
System.out.print("Enter roll number : ");
int rollNumber=Integer.parseInt(bufferedReader.readLine());
System.out.print("Enter name : ");
String name=bufferedReader.readLine();
File file=new File("friends.data");
RandomAccessFile randomAccessFile;
randomAccessFile=new RandomAccessFile(file,"rw");
randomAccessFile.seek(randomAccessFile.length());
randomAccessFile.writeBytes(String.valueOf(rollNumber));
randomAccessFile.writeBytes("\n");
randomAccessFile.writeBytes(name);
randomAccessFile.writeBytes("\n");
randomAccessFile.close();
System.out.println("Student added");
}catch(IOException ioException)
{
System.out.println(ioException);
}catch(NumberFormatException numberFormatException)
{
System.out.println(numberFormatException);
}
}
}
