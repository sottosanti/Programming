
import javassist.tools.reflect.Loader;
import javassist.tools.reflect.Metalevel;
import javassist.tools.reflect.Metaobject;

public class HW1 {

    public void startHW() throws Exception {
		A a = new A();
		B b = new B();
		C c = new C();

		a.foo();
		b.foo();
		c.foo();
		a.foo();

	}

	public static void main(String[] args) throws Exception {

		HW1 myHW = new HW1();
		myHW.startHW();

	}

}
