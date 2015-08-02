package com.smmahdad.filter.test;

import com.smmahdad.filter.src.FileFilter;
import static org.junit.Assert.assertTrue;
import org.junit.Test;


public class FileFilterTest {

	@Test
	public void testWhenFileExists() {
		assertTrue(FileFilter.checkIfFileExists("testFiles/RandomText.txt") == 1);
	}

	@Test
	public void testWhenFileNotFound() {
		assertTrue(FileFilter.checkIfFileExists("testFiles/RandomBlarjgaldkjfga.txt") == 0);
	}

	@Test
	public void testWhenDirectory() {
		assertTrue(FileFilter.checkIfFileExists("testFiles") == 2);
	}
}