<!DOCTYPE html>
<!-- http://goo.gl/9i9bIP -->
<html lang = "en">
<head>
	<meta charset = "UTF-8" />
	<title> Computing Taxes </title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<?php require_once 'employee.php'; ?>

	<h1> GeneriCorp's Bland Payroll Page </h1>

	<?php 
		$payroll = array();
		$payroll[0] = new Employee("Bob", 0, 2);		 /* One Argument */ 
		$payroll[1] = new Employee("Christopher", 12);	 /* Two Arguments */ 
		$payroll[2] = new Employee("José", 9, 4);		 /* Three Arguments */ 
		$payroll[3] = new Employee("Stephanie", -100);	 /* Invalid Wage */ 
		$payroll[4] = new Employee("Stacey", 18, -100);	 /* Too Few Dependents */ 
		$payroll[5] = new Employee("Chelsea", 24, 12);	 /* Too Many Dependents */ 	
	?>
	<form action = "index.php" method = "post">
		<label class = "rAlign" ><?php echo $payroll[0].": " ?></label><!-- Here's the first time I use __toString() -->
		<input 	type  = "text"
				name  = "employee0"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee0']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[0], 
						$_POST["employee0"], 
						$payroll[0]->computePay($_POST["employee0"])); 
			}
		?>
		<br />

		<label class = "rAlign" ><?php echo $payroll[1].": " ?></label>
		<input 	type  = "text"
				name  = "employee1"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee1']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[1], 
						$_POST["employee1"], 
						$payroll[1]->computePay($_POST["employee1"])); 
			}
		?>
		<br />

		<label class = "rAlign" ><?php echo $payroll[2].": " ?></label>
		<input 	type  = "text"
				name  = "employee2"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee2']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[2], 
						$_POST["employee2"], 
						$payroll[2]->computePay($_POST["employee2"])); 
			}
		?>
		<br />

		<label class = "rAlign" ><?php echo $payroll[3].": " ?></label>
		<input 	type  = "text"
				name  = "employee3"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee3']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[3], 
						$_POST["employee3"], 
						$payroll[3]->computePay($_POST["employee3"])); 
			}
		?>
		<br />

		<label class = "rAlign" ><?php echo $payroll[4].": " ?></label>
		<input 	type  = "text"
				name  = "employee4"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee4']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[4], 
						$_POST["employee4"], 
						$payroll[4]->computePay($_POST["employee4"])); 
			}
		?>
		<br />

		<label class = "rAlign" ><?php echo $payroll[5].": " ?></label>
		<input 	type  = "text"
				name  = "employee5"
				onclick = "this.value='';"
				value = <?php
							if (isset($_POST["employee0"])) echo "\"{$_POST['employee5']}\"";
							else print '"Input Hours Worked"';
						?> />
		<?php 
			if(isset($_POST["submit"])) { 
				printf ("<span>Name: %s </span>
						 <span>Hours Worked: <span class=\"rAlign\" >%d</span></span>
						 <span>Pay Due: <span class = \"rAlign\" >$%.2f</span></span>", 
						$payroll[5], 
						$_POST["employee5"], 
						$payroll[5]->computePay($_POST["employee5"])); 
			}
		?>
		<br />

		<input type = "submit" name = "submit" value = "Submit" />
	</form>
</body>
</html>
