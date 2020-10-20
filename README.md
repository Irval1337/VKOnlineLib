## VKOnlineChecker
Библиотека помогает определить онлайн пользователя ВКонтакте без использования API сайта. Исходный код написан на C/C++ и может быть использован не только для .NET Framework приложений, однако в чистом виде библиотека работает только на C# и Basic.

Пример реализации на C#:
``` C#
OnlineLib.Class lib = new OnlineLib.Class();
        
        static void Main(string[] args)
        {
            if (new OnlineLib.Class().GetOnlineAdmin("irval26"))
            {
                Console.WriteLine("Online");
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("Offline");
                Console.ReadKey();
            }
        }
```
В случае возникновения проблем/вопросов/предложений, прошу вас писать в Telegram (https://t.me/Irval1337) или ВКонтакте (https://vk.com/irval26) разработчику программы.
