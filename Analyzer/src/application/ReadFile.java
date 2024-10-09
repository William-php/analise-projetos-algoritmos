package application;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public  class ReadFile {
	private File myFile;
	private int n;
	private int k;
	private String nameFunction;
	private String lastNameFunction;
	private int recursion;
	private boolean recursionBool;
	private int nElevated;
	private int openLoop;

	public ReadFile (File myFile) {
		this.myFile = myFile;
		this.n = 0;
		this.k = 0;
		this.recursion = 0;
		this.nElevated = 1;
		this.openLoop = 0;
		this.nameFunction = "";
		this.recursionBool = false;
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

		this.getFunctionName(data);
		if (data.contains(this.nameFunction) && this.nameFunction.length() > 0) {						
			if (this.lastNameFunction.compareTo(this.nameFunction) > 0 && !this.lastNameFunction.contains("sizeof")) {
				this.recursionBool = true;
				return;
			}
			
		}
		
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
	
	public void getFunctionName(String data) {
		String[] arrayData = data.split(" ");
		
		for (String str : arrayData) {
			if (str.contains("(")) {
				this.lastNameFunction = this.nameFunction;
				this.nameFunction = str.substring(0, str.indexOf("("));
			}
		}
        
	}
	
	public void result() {		
		if (this.recursionBool) {
			System.out.println("Notação O (pior caso): O(nlogn)");
			return;
		}
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
