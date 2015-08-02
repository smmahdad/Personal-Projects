package com.smmahdad.startup;

import com.smmahdad.runner.Distributor;

public class Startup {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.out.println("You did not enter a file path");
			return;
		}
		
		String fileName = args[0];
		Distributor.filteringBasedOnExistence(fileName);
	}
}