package com.sxt.thread;

public class StaticProxy {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
 new WedingCompany(new You()).happyMarry();
	}

}
interface Marry{
	void happyMarry();
}
class You implements Marry{

	@Override
	public void happyMarry() {
		// TODO 自动生成的方法存根
		System.out.println("你可以结婚啦");
	}
	
}
class WedingCompany implements Marry{
private Marry target;
public WedingCompany(Marry target) {	// TODO 自动生成的构造函数存根
	this.target=target;
	
}
	@Override
	public void happyMarry() {
		// TODO 自动生成的方法存根
		ready();
		this.target.happyMarry();
		after();
		
	}
	private void ready() {
	System.out.println("布置主卧");	
	}
	private void after() {
		System.out.println("闹洞房");
	}
	
	
}
