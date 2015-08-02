package com.smmahdad.filter.test;

import com.smmahdad.filter.src.FileFilter;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import org.junit.Test;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class FileFilterTest {

	@Test
	public void testExistenceWhenFileExists() {
		assertTrue(FileFilter.checkIfFileExists("testFiles/RandomText.txt") == 1);
	}

	@Test
	public void testExistenceWhenFileNotFound() {
		assertTrue(FileFilter.checkIfFileExists("testFiles/RandomBlarjgaldkjfga.txt") == 0);
	}

	@Test
	public void testExistenceWhenDirectory() {
		assertTrue(FileFilter.checkIfFileExists("testFiles") == 2);
	}

	@Test
	public void testIfTextFileWhenItIs() {
		assertTrue(FileFilter.checkIfFileIsATxtFileSimple("testFiles/RandomText.txt"));
	}

	@Test
	public void testIfTextFileWhenItIsNot() {
		assertFalse(FileFilter.checkIfFileIsATxtFileSimple("testFiles/FakeImage.jpg"));
	}

}