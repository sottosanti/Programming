/* 
 * Aspect J, HW2
 * By: Stephen Sottosanti 
 * 
 * */

public aspect Profiling percflow(timer()){
	pointcut timer() : execution(* *.*(..));
	long start, end;
	
	before() : timer() {
		start = System.currentTimeMillis();
		System.out.println("Entering " + thisJoinPoint.getSignature().getDeclaringTypeName() + "::" +thisJoinPoint.getSignature().getName() + "...");
	}
	
	after() : timer() {
		long end = System.currentTimeMillis();
		System.out.println("Leaving " + thisJoinPoint.getSignature().getDeclaringTypeName() + "::" +thisJoinPoint.getSignature().getName() + ". Time spent: " + ((end - start)/1000.0) + "s");
	}
			
}