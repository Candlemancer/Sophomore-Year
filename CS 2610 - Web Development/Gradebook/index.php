<!DOCTYPE html>
<!-- http://goo.gl/m3Y83K -->
<html lang = "en">
	<head>
		<meta charset = "UTF-8" />
		<title>Storing Scores</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>

		<!-- Navigation -->
		<div id = "Nav">
			<H1> Newspaper Gradebook </H1>

			<form action = "index.php" method = "POST" >
				<input type = "submit" name = "newStudentB" 	value = "New Student" />
				<input type = "submit" name = "newAssignmentB" 	value = "New Assignment" />
				<input type = "submit" name = "enterGradesB" 	value = "Enter Grades" />
				<input type = "submit" name = "showGradesB" 	value = "Show Grades" />
			</form>
		</div>

		<!-- Database Connection -->
		<?php 

			$database = new mysqli('localhost', 'candlemancer', 'i+v5=WiN', 'candlemancer');
			if($database->connect_error) {
				echo "COULD NOT CONNECT TO DATABASE! OH NOES!";
			}

		?>

		<hr/>

		<?php

		?>

		<!-- New Student -->
		<?php 

			function validateNewStudent() {

				global $FirstNameE, $LastNameE, $PhoneE, $MajorE;
				global $firstName, $lastName, $phone, $major;

				//Clean the values
				$firstName = 	trim(htmlentities($_POST["FirstNameI"]));
				$lastName = 	trim(htmlentities($_POST["LastNameI"]));
				$phone = 		trim(htmlentities($_POST["PhoneI"]));
				$major = 		trim(htmlentities($_POST["MajorI"]));

				//Validate Phone
				if(!preg_match('#^(([2-9]\d\d-){1,2}\d{4}|([2-9]\d\d){1,2}\d{4}|([2-9]\d\d\.){1,2}\d{4}|([2-9]\d\d ){1,2}\d{4})$#', $_POST["PhoneI"] )) {
					$PhoneE = "Not a Valid Phone"; }
				if(empty($_POST["FirstNameI"])) { $FirstNameE = "Please Enter a Value"; }
				if(empty($_POST["LastNameI"])) 	{ $LastNameE = "Please Enter a Value"; 	}
				if(empty($_POST["PhoneI"])) 	{ $PhoneE = "Please Enter a Value"; 	}
				if(empty($_POST["MajorI"])) 	{ $MajorE = "Please Enter a Value"; 	}

				if(!empty($FirstNameE) || !empty($LastNameE) || !empty($PhoneE) || !empty($MajorE)) return false;

				return true;
			}

			// Initialize Messages
			$NewStudentMessage = "";
			$FirstNameE = "";
			$LastNameE = "";
			$PhoneE = "";
			$MajorE = "";

			//Initialize Database Info
			$firstName = "";
			$lastName = "";
			$phone = "";
			$major = "";


			if(isset($_POST["NewStudentSubmitB"])) {

				if (validateNewStudent()) {

					$phone = preg_replace("#[-\. ]{1}#", "", $phone);

					$firstName = $database->real_escape_string($firstName);
					$lastName = $database->real_escape_string($lastName);
					$phone = $database->real_escape_string($phone);
					$major = $database->real_escape_string($major);	

					if ($database->query("INSERT INTO student(first, last, phone, major) VALUES ('$firstName', '$lastName', '$phone', '$major')"))
						$NewStudentMessage = "Student Added Successfully!";
					else $NewStudentMessage = "Unable to add Student. Please contact your System Administrator.";

					$firstName = "";
					$lastName = "";
					$phone = "";
					$major = "";
				}

			}

		?>

		<?php if(isset($_POST["newStudentB"]) || isset($_POST["NewStudentSubmitB"])) { ?>
			<div class = "content" >
				<?php echo $NewStudentMessage . "<br\>"; ?>
				<form action = "index.php" method = "POST" >
					<label>First Name:</label>
					<input type = "text" name = "FirstNameI" value = "<?php echo $firstName; ?>" size = "30" maxlength = "30" />
					<?php echo '<div class="error">' . $FirstNameE . '</div>'; ?>
					<br/>

					<label>Last Name:</label>
					<input type = "text" name = "LastNameI" value = "<?php echo $lastName; ?>" size = "30" maxlength = "30" />
					<?php echo '<div class="error">' . $LastNameE . '</div>'; ?>
					<br/>

					<label>Phone:</label>
					<input id = "phone" type = "text" name = "PhoneI" value = "<?php echo $phone; ?>" size = "12" maxlength = "12" />
					<?php echo '<div class="error">' . $PhoneE . '</div>'; ?>
					<br/>

					<label>Major:</label>
					<input type = "text" name = "MajorI" value = "<?php echo $major; ?>" size = "30" maxlength = "30" />
					<?php echo '<div class="error">' . $MajorE . '</div>'; ?>
					<br/>

					<input type = "submit" name = "NewStudentSubmitB" value = "Submit" />
				</form>
			</div>
		<?php } ?>

		<!-- New Assignment -->
		<?php 

			function validateNewAssignment() {

				global $AssignmentTypeE, $AssignmentNameE, $TotalPointsE;
				global $assignmentType, $assignmentName, $totalPoints;

				//Clean the values
				$assignmentType = 	$_POST["AssignmentTypeDD"];
				$assignmentName = 	trim(htmlentities($_POST["AssignmentNameI"]));
				$totalPoints = 		trim(htmlentities($_POST["TotalPointsI"]));

				if(!is_numeric($_POST["TotalPointsI"]))	{ $TotalPointsE = "Invalid Point Value"; }
				if($_POST["TotalPointsI"] < 0)	 		{ $TotalPointsE = "Invalid Point Value"; }
				if(empty($_POST["AssignmentTypeDD"])) 	{ $AssignmentTypeE = "Please Enter a Value"; }
				if(empty($_POST["AssignmentNameI"])) 	{ $AssignmentNameE = "Please Enter a Value"; }
				if(empty($_POST["TotalPointsI"])) 		{ $TotalPointsE = "Please Enter a Value"; }

				if(!empty($AssignmentTypeE) || !empty($AssignmentNameE) || !empty($TotalPointsE) ) return false;

				return true;
			}

			// Initialize Messages
			$NewAssignmentMessage = "";
			$AssignmentTypeE = "";
			$AssignmentNameE = "";
			$TotalPointsE = "";

			//Initialize Database Info
			$assignmentType = "";
			$assignmentName = "";
			$totalPoints = "";


			if(isset($_POST["NewAssignmentSubmitB"])) {

				if (validateNewAssignment()) {

					$assignmentName = $database->real_escape_string($assignmentName);
					$totalPoints = $database->real_escape_string($totalPoints);

					if ($database->query("INSERT INTO gradebook(type, name, maxScore) VALUES ('$assignmentType', '$assignmentName', $totalPoints)"))
						$NewAssignmentMessage = "Assignment Added Successfully!";
					else $NewAssignmentMessage = "Unable to add Assignment. Please contact your System Administrator.";

					$assignmentType = "";
					$assignmentName = "";
					$totalPoints = "";
				}

			}

		?>

		<?php if(isset($_POST["newAssignmentB"]) || isset($_POST["NewAssignmentSubmitB"])) { ?>
		<div class = "content" >
			<?php echo $NewAssignmentMessage . "<br\>"; ?>
			<form id = "NewAssignmentF" action = "index.php" method= "POST" >
				<label>Assignment Type:</label>
				<select form = "NewAssignmentF" name = "AssignmentTypeDD" >
					<option value = "HW">Homework</option>
					<option value = "Quiz">Quiz</option>
					<option value = "Exam">Exam</option>
				</select>
				<?php echo '<div class = "error" >' . $AssignmentTypeE . '</div>'; ?>
				<br/>

				<label>Assignment Name:</label>
				<input type = "text" name = "AssignmentNameI" value = "<?php echo $assignmentName; ?>" size = "30" maxlength = "30" />
				<?php echo '<div class = "error" >' . $AssignmentNameE . '</div>'; ?>
				<br />

				<label>Total Possible Points:</label>
				<input id = "points" type = "text" name = "TotalPointsI" value = "<?php echo $totalPoints; ?>" size = "5" maxlength = "5" />
				<?php echo '<div class = "error" >' . $TotalPointsE . '</div>'; ?>
				<br />

				<input type = "submit" name = "NewAssignmentSubmitB" value = "Submit" />
			</form>
		</div>
		<?php } ?>

		<!-- Input Scores -->
		<!-- View Scores -->

	</body>
</html>
