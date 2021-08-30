

import javassist.tools.reflect.*;
import javassist.tools.reflect.Metalevel;
import javassist.tools.reflect.Metaobject;

import javassist.*;


public class VerboseMetaobj extends Metaobject {
	
    public VerboseMetaobj(Object self, Object[] args)  throws Throwable {
        super(self, args);
        ClassPool cp = ClassPool.getDefault();
        
        CtClass cc = cp.get(self.getClass().getName());
        CtMethod[] m = cc.getDeclaredMethods();
        
        for (int i=0; i < m.length; i++) {
        	
			m[i].addLocalVariable("startTimer", CtClass.longType);
			m[i].addLocalVariable("endTimer", CtClass.longType);

			m[i].insertBefore("{ startTimer = System.currentTimeMillis(); System.out.print(\"Entering " + cc.getName() + "::\"); System.out.println(\"" + m[i].getName() + "...\"); }");  
			m[i].insertAfter("{ endTimer = System.currentTimeMillis(); "
					+ "System.out.print(\"Leaving " + cc.getName() + "::\"); System.out.println(\"" + m[i].getName() + ". Time spent: \" + ((endTimer - startTimer)/1000.0) + \"s\"); }");

		}
        			
        cc.writeFile();
        
        String[] classnames = {"A", "B", "C"};
        CtClass[] classes = cp.get(classnames);
        
        for (int j=0; j < classes.length; j++) {
        	CtMethod[] methods = classes[j].getDeclaredMethods();
			
        	for (int i=0; i < methods.length; i++) {
	
				methods[i].addLocalVariable("startTimer", CtClass.longType);
				methods[i].addLocalVariable("endTimer", CtClass.longType);
	
				methods[i].insertBefore("{ startTimer = System.currentTimeMillis(); System.out.print(\"Entering " + classes[j].getName() + "::\"); System.out.println(\"" + methods[i].getName() + "...\"); }");  
				methods[i].insertAfter("{ endTimer = System.currentTimeMillis(); "
						+ "System.out.print(\"Leaving " + classes[j].getName() + "::\"); System.out.println(\"" + methods[i].getName() + ". Time spent: \" + ((endTimer - startTimer)/1000.0) + \"s\"); }");
	
			}
        	
        	classes[j].writeFile();
        }
		
    }

    
}
