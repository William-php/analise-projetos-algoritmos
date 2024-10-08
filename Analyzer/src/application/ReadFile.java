package application;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public  class ReadFile {
	private File myFile;
	private int n;
	private int k;
	//private int logN;
	private int nElevated;
	private int openLoop;
	//private int closeLoop;
	public ReadFile (File myFile) {
		this.myFile = myFile;
		this.n = 0;
		this.k = 0;
		//this.logN = 0;
		this.nElevated = 1;
		this.openLoop = 0;		
	}
	public void read() {
		try {
			//File myFile = new File("./Files/test.txt");
			Scanner myReader = new Scanner(this.myFile);
			
			while (myReader.hasNextLine()) {
				String data = myReader.nextLine();
				this.analyzer(data);
			}
		} catch (FileNotFoundException error) {
			System.out.println("Deu ruim");
			error.printStackTrace();
		}
	}
	
	public void analyzer(String data) {

		
		if (data.indexOf("openLoop") > 0 && this.openLoop == 0) {			
			this.openLoop++;
			this.n++;
			this.k++;
			return;
		}
		if (data.length() > 0 && !data.contains("}")) {
			this.k++;
		}
		if (data.indexOf("closeLoop") > 0) {
			this.openLoop = 1;
			return;
		}
		if (this.openLoop > 0 && data.indexOf("openLoop") > 0) {
			this.nElevated++;
			if (this.n > 0) this.n--;
		}
	}
	
	public void result() {
		System.out.println("n: " + this.n + "nElevated: " + this.nElevated + "k: " + this.k);
		if (this.n > 0 && this.nElevated == 1) {
			System.out.println("Análise assintótica: " + this.n + "n" + " + " + this.k);
			System.out.println("Notação O (pior caso): O(n)");
			return;
		}
		if (this.n > 0 && this.nElevated > 1) {
			System.out.println("Análise assintótica: n^" + this.nElevated + " + "  + this.n + "n" + " + " + this.k);
			System.out.println("Notação O (pior caso): O(n^" + this.nElevated + ")");
			return;
		}
		if (this.n <= 0 && this.nElevated > 1) {
			System.out.println("Análise assintótica: n^" + this.nElevated  + " + " + this.k);
			System.out.println("Notação O (pior caso): O(n^" + this.nElevated + ")");
			return;
		}
		
		
	}
	
}
