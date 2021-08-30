
import java.io.*;

public class A {

	  InputStreamReader r = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(r);
	  String name;
	
	  public void bar() throws Exception 
	  {
		  System.out.print("Please enter last name: ");
		  name = br.readLine();  
	  }
	  
	  public void foo() throws Exception 
	  {
		  System.out.print("Please enter first name: ");
		  name = br.readLine();  
		  
		  bar();
	  }
	  
}
