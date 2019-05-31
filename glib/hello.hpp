#ifndef GLIB_HELLO_H
#define GLIB_HELLO_H

#include <glib-object.h>

G_BEGIN_DECLS

#define HELLO_TYPE_GREETING (hello_greeting_get_type())

G_DECLARE_DERIVABLE_TYPE(HelloGreeting,
                         hello_greeting,
                         HELLO,
                         GREETING,
                         GObject)

struct _HelloGreetingClass
{
  GObjectClass parent_class;
};

HelloGreeting *hello_greeting_new(void);
void hello_greeting_message(HelloGreeting *greeting, const gchar *msg);

G_END_DECLS

#endif
