package com.sxt.thread;

public class Threadnoauto implements Runnable {
	
	public int ticketNums=50;
	
	@Override
	public void run() {
		while(true){
			while(ticketNums>0) {
				break;
			
			}
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"-->"+ticketNums--);
			
		}
		
	}

	
	public static void main(String[] args) {
		// TODO 自动生成的方法存根

		Threadnoauto web=new Threadnoauto();
		new Thread(web,"a").start();
		new Thread(web,"b").start();
		new Thread(web,"c").start();
	}

}
