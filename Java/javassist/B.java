

import java.io.*;

public class B {

	  InputStreamReader r = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(r);
	  String name;
	
	  public void bar() throws Exception 
	  {
		  System.out.print("Please enter cell phone: ");
		  name = br.readLine();  
	  }
	  
	  public void foo() throws Exception 
	  {
		  System.out.print("Please enter home phone: ");
		  name = br.readLine();  
		  
		  bar();
	  }
	  
}
