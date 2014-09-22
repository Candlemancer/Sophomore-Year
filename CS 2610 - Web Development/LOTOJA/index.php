<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" />
		<title>LOTOJA Race Times</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<div>
			<h1>Logan, UT to Jackson, WY Race Statistics</h1>
		</div>

		<!-- Input Form -->
		<form action="index.php" method="post">
			<div class="error"></div>
			<label 	id="racerNameL" class="formLabel">Racer Name:</label>
			<input 	id = "racerNameI" 
					name = "racerName" 
					type = "text" 
					value = '<?php if( isset($_POST["racerName"]) && isset($_POST["submitButton"])) {
									   	echo $_POST["racerName"]; 
								   }	?>' 
					/>
			<div class="error">
				<?php 
					if(empty($_POST["racerName"]) && isset($_POST["submitButton"])) {
						echo "Please Enter a Name";
					}
				?>
			</div>
			<br/>
			<br/>


			<div class="error"></div>
			<label class = "formLabel">Checkpoint One Time: </label>
			<input  name = "time[]" 
					type = "text" 
					value = '<?php if( isset($_POST["time"][0]) && isset($_POST["submitButton"])) {
									   	echo $_POST["time"][0]; 
								   }	?>'
			/>
			<div class="error">
				<?php 
					echo error(0);
				?>
			</div>
			<br/>

			<div class="error"></div>
			<label class = "formLabel">Checkpoint Two Time: </label>
			<input	name = "time[]" 
					type = "text" 
					value = '<?php if( isset($_POST["time"][1]) && isset($_POST["submitButton"])) {
									   	echo $_POST["time"][1]; 
								   }	?>'
			/>
			<div class="error">
				<?php 
					echo error(1);
				?>
			</div>
			<br/>

			<div class="error"></div>
			<label class = "formLabel">Checkpoint Three Time: </label>
			<input	name = "time[]" 
					type = "text" 
					value = '<?php if( isset($_POST["time"][2]) && isset($_POST["submitButton"])) {
									   	echo $_POST["time"][2]; 
								   }	?>'
			/>
			<div class="error">
				<?php 
					echo error(2);
				?>
			</div>
			<br/>


			<div class="error"></div>
			<label class = "formLabel">Checkpoint Four Time: </label>
			<input	name = "time[]" 
					type = "text" 
					value = '<?php if( isset($_POST["time"][3]) && isset($_POST["submitButton"])) {
									   	echo $_POST["time"][3]; 
								   }	?>'
			/>
			<div class="error">
				<?php 
					echo error(3);
				?>
			</div>
			<br/>


			<div class="error"></div>
			<label class = "formLabel">Checkpoint Five Time: </label>
			<input	name = "time[]" 
					type = "text" 
					value = '<?php if( isset($_POST["time"][4]) && isset($_POST["submitButton"])) {
									   	echo $_POST["time"][4]; 
								   }	?>'
			/>
			<div class="error">
				<?php 
					echo error(4);
				?>
			</div>
			<br/>
			<br/>

			<input name="submitButton" type="submit" value="Submit" />
			<input name="clearButton"  type="submit" value="Clear"  />
		</form>

		<!-- Input Handling -->
		<?php 

			// Variable Initializations
			define("MIN_PER_HOUR", "60");
			$dist = array(44, 43, 41, 37, 42);
			$time = array();
			$rate = array();
			$name = "";

			$totals = array( "dist" => 0, 
							 "time" => 0,
							 "rate" => 0 );

			//Calculations on Submit
			if(isset($_POST["submitButton"])) {

				$name = $_POST["racerName"];

				foreach ($_POST["time"] as $k => $v) {
					if($k == 0) { $time[] = $v; continue; }
					$time[] = $v - array_sum($time);
				}

				foreach ($dist as $k1 => $v1) {
					if ($time[$k1] == 0) { $rate[$k1] = "Undefined"; continue; }
					$rate[$k1] = ($v1 / $time[$k1]) * MIN_PER_HOUR;				
				}

				//Fill out the totals
				foreach ($dist as $v2) {
					$totals["dist"] += $v2;	
				}

				foreach ($time as $v3) {
					$totals["time"] += $v3;
				}

				if (array_sum($time) != 0) { 
					$totals["rate"] = array_sum($dist) / array_sum($time) * MIN_PER_HOUR; 
				}

			}

			//print_r($_POST);

		?>

		<!-- Output Table -->
		<?php if ( isset($_POST["submitButton"]) && 
				   !empty($_POST["racerName"])	 &&
				   !error(0)					 &&
				   !error(1)					 &&
				   !error(2)				  	 &&
				   !error(3)					 &&
				   !error(4)					 ) { ?>
			<table> 
				<tr>
					<td colspan="4">
						<h2>Race Statistics for <?php printf("%s", htmlentities($name)); ?></h2>
					</td>
				</tr>
				<tr>
					<th> </th>
					<th>Segment Distance</th>
					<th>Segment Time</th>
					<th>Segment Speed</th>
				</tr>
				<tr>
					<td class="data"><strong>Segment One:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d miles"), 	$dist[0]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%d minutes"), 	$time[0]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%2.2f mph"), 	$rate[0]); ?> </td>
				</tr>
				<tr>
					<td class="data"><strong>Segment Two:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d miles"), 	$dist[1]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%d minutes"), 	$time[1]); ?> </td>	
					<td class="data"> <?php printf(htmlentities("%2.2f mph"), 	$rate[1]); ?> </td>
				</tr>
				<tr>
					<td class="data"><strong>Segment Three:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d miles"), 	$dist[2]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%d minutes"), 	$time[2]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%2.2f mph"), 	$rate[2]); ?> </td>
				</tr>
				<tr>
					<td class="data"><strong>Segment Four:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d miles"), 	$dist[3]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%d minutes"),	$time[3]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%2.2f mph"), 	$rate[3]); ?> </td>
				</tr>
				<tr>
					<td class="data"><strong>Segment Five:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d miles"), 	$dist[4]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%d minutes"),	$time[4]); ?> </td>
					<td class="data"> <?php printf(htmlentities("%2.2f mph"), 	$rate[4]); ?> </td>
				</tr>
				<tr>
					<td class="data"><strong>OVERALL:</strong></td>
					<td class="data"> <?php printf(htmlentities("%d total miles"), 	 $totals["dist"]);?> </td>
					<td class="data"> <?php printf(htmlentities("%d total minutes"), $totals["time"]);?> </td>
					<td class="data"> <?php printf(htmlentities("%2.2f avg. mph"),	 $totals["rate"]);?> </td>
				</tr>
			</table>
		<?php } ?>

		<?php 
			function error($index) {

				if (isset($_POST["submitButton"])) {
					if( $_POST["time"][$index] == "") { return "Time cannot be left blank"; }
					if( !is_numeric($_POST["time"][$index])) { return "Please enter a number"; }
					if( $index == "0" && $_POST["time"][$index] <= 0) { return "Time must be greater than zero"; }
					if( $index != 0 && ($_POST["time"][$index] <= $_POST["time"][$index - 1])) { return "Times must be cumulative"; }
				}

				return FALSE;
			}
		?>

	</body>
</html>















