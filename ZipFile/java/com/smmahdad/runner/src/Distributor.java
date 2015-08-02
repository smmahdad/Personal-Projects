package com.smmahdad.runner.src;

import com.smmahdad.filter.src.FileFilter;
import java.util.InputMismatchException;
import com.smmahdad.unzipper.src.UnzipBasic;

public class Distributor {
	public static void filteringBasedOnExistence(String fileName) {
		int filterResponse = FileFilter.checkIfFileExists(fileName);

		if (filterResponse == 0) {
			System.out.println("File path cannot be found");
		} else if (filterResponse == 2) {
			System.out.println("File path leads to a directory");
		} else if (filterResponse == 1) {
			//Do something
			System.out.println("Made it!");
			Distributor.filteringBasedOnFileType(fileName);
		} else {
			throw new RuntimeException("Filter threw unexpected response");
		}
	}

	public static void filteringBasedOnFileType(String fileName) {
		if (FileFilter.checkIfFileIsATxtFileSimple(fileName)) {
			System.out.println("You are a text file");
			//Have to determine how I want to decide whether or not to unzip
			// UnzipBasic.unzip(fileName);
		} else {
			System.out.println("File is not a text file");
		}
	}
}