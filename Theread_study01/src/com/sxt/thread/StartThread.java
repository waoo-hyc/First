package com.sxt.thread;

public class StartThread extends Thread {
	public void run()
	{
		for(int i=0;i<20;i++)
			System.out.println("һ������");
	}
public static void main(String[] args) {
		// TODO �Զ����ɵķ������
	StartThread st=new StartThread();
	st.start();
	for(int i=0;i<20;i++)
		System.out.println("һ��coding");
	}

}
