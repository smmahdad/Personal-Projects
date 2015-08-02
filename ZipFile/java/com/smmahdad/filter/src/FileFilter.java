package com.smmahdad.filter.src;

import java.io.File;

public class FileFilter {
	public static int checkIfFileExists(String fileName) {
		File f = new File(fileName);
		if(f.exists() && !f.isDirectory()) { 
			//file exists
			return 1;
		} else if (f.exists()) {
			//fileName is really a directory
			return 2;
		} else {
			//cannot be found
			return 0;
		}
	}

	public static boolean checkIfFileIsATxtFileSimple(String fileName) {
		if (fileName.length() <= 4) {
			return false;
		}

		return fileName.substring(fileName.length() - 4).equals(".txt");
	}
}