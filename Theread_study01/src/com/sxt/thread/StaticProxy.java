package com.sxt.thread;

public class StaticProxy {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
 new WedingCompany(new You()).happyMarry();
	}

}
interface Marry{
	void happyMarry();
}
class You implements Marry{

	@Override
	public void happyMarry() {
		// TODO �Զ����ɵķ������
		System.out.println("����Խ����");
	}
	
}
class WedingCompany implements Marry{
private Marry target;
public WedingCompany(Marry target) {	// TODO �Զ����ɵĹ��캯�����
	this.target=target;
	
}
	@Override
	public void happyMarry() {
		// TODO �Զ����ɵķ������
		ready();
		this.target.happyMarry();
		after();
		
	}
	private void ready() {
	System.out.println("��������");	
	}
	private void after() {
		System.out.println("�ֶ���");
	}
	
	
}
