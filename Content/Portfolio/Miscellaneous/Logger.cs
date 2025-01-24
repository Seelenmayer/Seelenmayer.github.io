using System;
using UnityEngine;
using Object = System.Object;

/* Custom console printer. */
namespace Logger
{
	public static class Logger
	{
		// Colour options
		private static Color32 red = new Color32(0xff, 0x00, 0x00, 0xff);
		private static Color32 orange = new Color32(0xff, 0x77, 0x00, 0xff);
		private static Color32 yellow = new Color32(0x00, 0xff, 0x00, 0xff);
		private static Color32 green = new Color32(0x00, 0xff, 0x00, 0xff);

		// Colour input
		public static string Color(this string myStr, Color32 colour)
		{
			return $"<color={Color32ToHex(colour)}>{myStr}</color>";
		}

		// Colour32 to Hex
		private static string Color32ToHex(Color32 colour)
		{
			return $"#{colour.r:x2}{colour.g:x2}{colour.b:x2}{colour.a:x2}";
		}

		// Create log
		private static void DoLog(Action<string, UnityEngine.Object> LogFunction, Color32 colour, string prefix, Object myObj, params object[] msg)
		{
#if UNITY_EDITOR

			string name;
			UnityEngine.Object obj = null;

			if (myObj == null)
			{
				// Null object
				name = "NullObject".Color(red);
			}
			else if (myObj is UnityEngine.Object)
			{
				// Unity object
				obj = (UnityEngine.Object)myObj;
				name = obj.name.Color(orange);
			}
			else 
			{
				// Miscellaneous object
				name = myObj.GetType().Name.Color(yellow);
			}

			// Execute formatted log
			var format = $"{prefix}[{name}]: {String.Join("; ", msg)}\n ".Color(colour);
			LogFunction(format, obj);
#endif
		}

		// Standard log call
		public static void Log(this Object myObj, params object[] msg)
		{
			DoLog(Debug.Log, orange, "", myObj, msg);
		}

		//Log success call
		public static void LogSuccess(this Object myObj, params object[] msg)
		{
			DoLog(Debug.Log, green, "", myObj, msg);
		}

		// Log warning call
		public static void LogWarning(this Object myObj, params object[] msg)
		{
			DoLog(Debug.LogWarning, yellow, "⚠️", myObj, msg);
		}

		// Log error call
		public static void LogError(this Object myObj, params object[] msg)
		{
			DoLog(Debug.LogError, red, "⚠️", myObj, msg);
		}
	}
}