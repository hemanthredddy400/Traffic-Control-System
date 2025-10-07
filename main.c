<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Traffic Control System</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="flex flex-col items-center justify-center min-h-screen bg-gray-100">

  <h1 class="text-3xl font-bold mb-6">🚦 Traffic Control System</h1>

  <!-- Traffic Light Box -->
  <div class="bg-black p-6 rounded-2xl flex flex-col space-y-4 items-center">
    <div id="red" class="w-20 h-20 rounded-full bg-red-500"></div>
    <div id="yellow" class="w-20 h-20 rounded-full bg-gray-300"></div>
    <div id="green" class="w-20 h-20 rounded-full bg-gray-300"></div>
  </div>

  <!-- Controls -->
  <div class="mt-6 space-x-4">
    <button onclick="changeLight()" 
      class="bg-blue-600 text-white px-4 py-2 rounded-lg shadow">
      Next Signal
    </button>
    <button onclick="startAuto()" 
      class="bg-green-600 text-white px-4 py-2 rounded-lg shadow">
      Auto Mode
    </button>
    <button onclick="stopAuto()" 
      class="bg-red-600 text-white px-4 py-2 rounded-lg shadow">
      Stop Auto
    </button>
  </div>

  <script>
    let state = 0;
    let autoInterval;

    function resetLights() {
      document.getElementById("red").className = "w-20 h-20 rounded-full bg-gray-300";
      document.getElementById("yellow").className = "w-20 h-20 rounded-full bg-gray-300";
      document.getElementById("green").className = "w-20 h-20 rounded-full bg-gray-300";
    }

    function changeLight() {
      resetLights();
      if(state === 0) {
        document.getElementById("red").className = "w-20 h-20 rounded-full bg-red-500";
        state = 1;
      } else if(state === 1) {
        document.getElementById("yellow").className = "w-20 h-20 rounded-full bg-yellow-500";
        state = 2;
      } else {
        document.getElementById("green").className = "w-20 h-20 rounded-full bg-green-500";
        state = 0;
      }
    }

    function startAuto() {
      stopAuto();
      changeLight(); // start immediately
      autoInterval = setInterval(changeLight, 2000); // change every 2 sec
    }

    function stopAuto() {
      clearInterval(autoInterval);
    }
  </script>

</body>
</html>
