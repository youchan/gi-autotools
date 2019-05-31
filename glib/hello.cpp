#include <memory>

#include "../src/greeting.hpp"

#include "./hello.hpp"

G_BEGIN_DECLS

typedef struct {
  std::shared_ptr<Hello::Greeting> greeting;
} HelloGreetingPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(HelloGreeting, hello_greeting, G_TYPE_OBJECT)

#define HELLO_GREETIN_GET_PRIVATE(obj)                     \
  (G_TYPE_INSTANCE_GET_PRIVATE((obj),                   \
                               HELLO_TYPE_GREETING,         \
                               HelloGreetingPrivate))

enum {
  PROP_0,
  PROP_GREETING
};

static void
hello_greeting_finalize(GObject *object)
{
  auto priv = HELLO_GREETIN_GET_PRIVATE(object);

  priv->greeting = nullptr;

  G_OBJECT_CLASS(hello_greeting_parent_class)->finalize(object);
}

static void
hello_greeting_set_property(GObject *object,
                        guint prop_id,
                        const GValue *value,
                        GParamSpec *pspec)
{
  auto priv = HELLO_GREETIN_GET_PRIVATE(object);

  switch (prop_id) {
  case PROP_GREETING:
    priv->greeting =
      *static_cast<std::shared_ptr<Hello::Greeting> *>(g_value_get_pointer(value));
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    break;
  }
}

static void
hello_greeting_init(HelloGreeting *object)
{
}

static void
hello_greeting_class_init(HelloGreetingClass *klass)
{
  GParamSpec *spec;

  auto gobject_class = G_OBJECT_CLASS(klass);

  gobject_class->finalize     = hello_greeting_finalize;
  gobject_class->set_property = hello_greeting_set_property;

  spec = g_param_spec_pointer("greeting",
                              "Greeting",
                              "The raw std::shared<Hello::Greeting> *",
                              static_cast<GParamFlags>(G_PARAM_WRITABLE |
                                                       G_PARAM_CONSTRUCT_ONLY));
  g_object_class_install_property(gobject_class, PROP_GREETING, spec);
}

/**
 * glib_hello_new:
 *
 * Returns: A newly created empty #GLibHello
 *
 * Since: 1.0.0
 */
HelloGreeting *
hello_greeting_new(void)
{
  auto hello_greeting= std::make_shared<Hello::Greeting>();
  auto greeting = g_object_new(HELLO_TYPE_GREETING, "greeting", &hello_greeting, NULL);
  return HELLO_GREETING(greeting);
}

void
hello_greeting_message(HelloGreeting *greeting, const gchar *msg)
{
  auto priv = HELLO_GREETIN_GET_PRIVATE(greeting);
  return priv->greeting->message(msg);
}

G_END_DECLS
