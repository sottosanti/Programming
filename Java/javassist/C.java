

import java.io.*;

public class C {

	  InputStreamReader r = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(r);
	  String name;
	
	  public void bar() throws Exception 
	  {
		  System.out.print("Please enter state: ");
		  name = br.readLine();  
	  }
	  
	  public void foo() throws Exception 
	  {
		  System.out.print("Please enter city: ");
		  name = br.readLine();  
		  
		  bar();
	  }
	  
}
