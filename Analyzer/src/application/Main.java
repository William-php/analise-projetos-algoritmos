package application;

import java.io.File;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String str = input.next();
		ReadFile reader = new ReadFile(new File(str));
		reader.read();
		reader.result();
		
	}
}
